#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
void solve() {
    int q, k; cin >> q >> k;
    vector<ll> dp(k + 1);
    dp[0] = 1;
    for (int i = 0; i < q; i++) {
        char t; int x;
        cin >> t; cin >> x;
        if (t == '+') {
            for (int i = k; i >= x; i--) {
                (dp[i] += dp[i - x]) %= mod;
            }
        } else {
            for (int i = x; i <= k; i++) {
                (dp[i] += mod - dp[i - x]) %= mod;
            }
        }
        cout << dp[k] << '\n';
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
