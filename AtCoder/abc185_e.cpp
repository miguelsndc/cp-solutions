#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x:a)cin>>x;
    for (int &x:b)cin>>x;
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0) dp[i][j] = i + j;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
        }
    }
    cout << dp[n][m] << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}