#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define array vector
#define scan cin
#define print cout
using namespace std;
using namespace __gnu_pbds;
#define int long long

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct card {
    int front, back;
};

struct helper {
    int value, i;
    
    bool operator<(const helper &other) const {
        if (value != other.value) return value > other.value;
        return i < other.i;
    }
};

int solve() {
    int n; scan >> n;
    oset<helper> s;
    array<card> a(n);
    for (int i = 0; i < n; ++i) {
        scan >> a[i].front;
    }
    for (int i = 0; i < n; ++i) {
        scan >> a[i].back;
    }
    int k, l; scan >> k >> l;
    int front = 0, back = 0;
    for (int i = 0; i < k; ++i) {
        front += a[i].front;
        s.insert({a[i].back, i});
    }
    for (int i = 0; i < l; ++i) {
        back += s.find_by_order(i)->value;
    }
    int best = front + back;
    int i = k - 1, j = n - 1;
    int id = -1;
    while (i >= 0) {
        front -= a[i].front;
        front += a[j].front;

        helper rem = {a[i].back, i};
        int x = s.order_of_key(rem);
        bool removed = false;
        if (x < l) {
            removed = true;
            back -= s.find_by_order(x)->value; 
        }
        s.erase(rem);

        helper add = {a[j].back, id--};
        int y = s.order_of_key(add);
        if (y < l) {
            if (!removed) back -= s.find_by_order(l - 1)->value;
            back += add.value;
        }

        s.insert(add);
        best = max(best, front + back);
        --i, --j;
    }
    return best;
}

signed main() {
    ios::sync_with_stdio(false), scan.tie(nullptr);
    print << solve() << '\n';
    return 0;
}
