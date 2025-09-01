#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n, k;
    cin >> n >> k;
    vc<ll> a(n);
    for (ll &i : a) cin >> i;

    ll ans = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (i == 0 or i == (n - 1)) {
                ans = max(ans, a[i] + a[n - 1 - i]);
            } else {
                ans = max(ans, a[i] + max(a[0], a[n - 1]));
            }
        }
    } else {
        sort(rall(a));
        for (int i = 0; i < k + 1; i++) {
            ans += a[i];
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