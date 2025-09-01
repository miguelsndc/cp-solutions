#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<ll> a(n);
    for (ll& x : a) cin >> x;
    ll x = a[0];
    for (int i = 1; i < n; i++) x &= a[i];

    if (x != 0) {
        cout << 1 << '\n';
        return;
    }

    ll flag = (1LL << 32) - 1;
    ll ans = 0, cur = flag;
    for (int i = 0; i < n; i++) {
        cur &= a[i];
        if (cur == x) {
            ans++;
            cur = flag;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}