#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

ll f(ll n) {
    return (n - 1) * n / 2;
}

void solve() {
    ll n;
    cin >> n;
    ll l = 2, r = 2e9, ans = 2e9;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (f(m) <= n) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    ll x = ans * (ans - 1) / 2;
    cout << ans + (n - x) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}