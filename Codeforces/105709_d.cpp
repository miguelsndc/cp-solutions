#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    vector<vector<int>> dp(m + 1, vector<int>(2));
    for (auto [w, v] : items) {
        for (int i = m; i >= 0; i--) {
            if (i + w <= m) {
                dp[i + w][0] = max(dp[i + w][0], dp[i][0] + v);
                dp[i + w][1] = max(dp[i + w][1], dp[i][1] + v);
            }
            dp[i][1] = max(dp[i][1], dp[i][0] + v);
        }
    }
    ll ans = -1;
    for (int j = 0; j <= 1; j++) {
        for (int i = 0; i <= m; i++) {
            ans = max(ans, (ll)dp[i][j]);
        }
    }
    cout << ans << '\n';
}