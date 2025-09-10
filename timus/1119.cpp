#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const double diag = 100 * sqrt(2.0);
const double side = 100;
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}
void solve() {
    int n, m; 
    cin >> n >> m;

    const double side = 100;
    const double diag = 100 * sqrt(2.0);

    vector<vector<double>> dp(n+1, vector<double>(m+1, 1e9));
    vector<vector<bool>> can(n, vector<bool>(m, false));

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        can[u-1][v-1] = true;
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = i * side;
    for(int j = 1; j <= m; j++) dp[0][j] = j * side;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            chmin(dp[i][j], dp[i-1][j] + side);
            chmin(dp[i][j], dp[i][j-1] + side);
            if(can[i-1][j-1])
                chmin(dp[i][j], dp[i-1][j-1] + diag);
        }
    }

    cout << round(dp[n][m]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}