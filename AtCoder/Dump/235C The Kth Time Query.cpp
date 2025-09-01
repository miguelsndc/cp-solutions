#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

// let's try sorting the list as (value, index pairs) then use equal_range
// if k isn't in the range [first, last) we are done
// if it is then we can use some math to calculate k
// if range is [3, 6), this means we have 3, 4, 5 occupied
// if (k - 1) + first

void solve(int n, int q) {
    int x, k;
    vector<pii> l(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i].f;
        l[i].s = i + 1;
    }
    sort(l.begin(), l.end());

    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        auto lbound = lower_bound(l.begin(), l.end(), x, [](pii a, const int b) {
                          return a.first < b;
                      }) -
                      l.begin();
        int p = k + lbound - 1;
        if (p > n - 1 || l[p].f != x) {
            cout << -1 << '\n';
        } else {
            cout << l[p].s << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    solve(n, q);
    return 0;
}