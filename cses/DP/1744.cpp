#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

vector dp(1000, vector<int>(1000, 1e9 + 1));
int f(int a, int b) {
    if (a == b) return dp[a][b] = dp[b][a] = 0;
    if (a == 1 or b == 1) return dp[a][b] = dp[b][a] = max(a, b) - 1;
    if (dp[a][b] != -1) return dp[a][b];
    int ans = 1e9;
    for (int i = 1; i <= a - 1; i++) {
        int k = 1 + f(i, b) + f(a - i, b);
        ans = min(ans, k);
    }
    for (int j = 1; j <= b - 1; j++) {
        int k = 1 + f(a, j) + f(a, b - j);
        ans = min(ans, k);
    }

    return dp[a][b] = dp[b][a] = ans;
}

void solve() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            for (int v = 1; v <= i - 1; v++) {
                dp[i][j] = min(dp[i][j], 1 + dp[v][j] + dp[i - v][j]);
            }
            for (int h = 1; h <= j - 1; h++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][h] + dp[i][j - h]);
            }
        }
    }
    cout << dp[a][b] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}