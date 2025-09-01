#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

class SegmentTree {
private:
    int n;
    vector<int> tree;
    void update(int pos, int val, int l, int r, int v) {
        if (l == r) {
            tree[v] += val;
        } else {
            int m = (l + r) / 2;
            if (pos <= m) {
                update(pos, val, l, m, v * 2 + 1);
            } else {
                update(pos, val, m + 1, r, v * 2 + 2);
            }
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }
    int query(int a, int b, int l, int r, int v) {
        if (a > r || b < l) return 0;
        if (l >= a and r <= b) return tree[v];
        int m = (l + r) / 2;
        int left = query(a, b, l, m, v * 2 + 1);
        int right = query(a, b, m + 1, r, v * 2 + 2);
        return left + right;
    }

public:
    SegmentTree(int sz) : n(sz) {
        tree.resize(4 * sz);
    }

    int qry(int a, int b) {
        return query(a, b, 0, n - 1, 0);
    }
    void upd(int pos, int val) {
        return update(pos, val, 0, n - 1, 0);
    }
};

void solve() {
    int n;
    cin >> n;
    SegmentTree segleft(n), segright(n);
    vector<int> a(n), c;
    for (int& x : a) {
        cin >> x;
    }
    c = a;
    sort(all(c));
    c.resize(unique(all(c)) - begin(c));
    map<int, int> mp;
    for (int i = 0; i < c.size(); i++) mp[c[i]] = i;
    for (int i = 0; i < n; i++) a[i] = mp[a[i]];

    vector<ll> left(n), right(n);
    for (int i = 0; i < n; i++) {
        left[i] = segleft.qry(min(a[i] + 1, n - 1), n - 1);
        segleft.upd(a[i], 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        right[i] = segright.qry(0, max(a[i] - 1, 0));
        segright.upd(a[i], 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += left[i] * right[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}