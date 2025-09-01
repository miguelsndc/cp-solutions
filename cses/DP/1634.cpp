#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

const int inf = 1e9 + 1;
void solve() {
    int n, sum;
    cin >> n >> sum;
    vector<int> dp(sum + 1, inf), coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    dp[0] = 0;
    for (int x = 1; x <= sum; x++) {
        for (auto c : coins) {
            if (x - c >= 0) {
                dp[x] = min(dp[x], dp[x - c] + 1);
            }
        }
    }
    cout << (dp[sum] == inf ? -1 : dp[sum]) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}
