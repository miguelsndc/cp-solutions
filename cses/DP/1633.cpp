#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    const int mod = 1e9 + 7;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int sum = 1; sum <= n; sum++) {
        for (auto coin : {1, 2, 3, 4, 5, 6}) {
            if (sum - coin >= 0) {
                dp[sum] += dp[sum - coin];
                dp[sum] %= mod;
            }
        }
    }
    cout << dp[n] % mod << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}