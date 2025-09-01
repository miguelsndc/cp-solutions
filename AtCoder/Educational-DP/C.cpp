#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

int n;
vector<vector<int>> choices(maxn, vector<int>(4));
int dp[maxn][4];
int solve_dp(int i, int prev = 0) {
    if (i == n) return 0;
    if (dp[i][prev] != -1) return dp[i][prev];
    int ans = 0;
    for (int j = 1; j <= 3; j++) {
        if (j != prev) ans = max(ans, choices[i][j] + solve_dp(i + 1, j));
    }
    return dp[i][prev] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> choices[i][1] >> choices[i][2] >> choices[i][3];
    }
    cout << solve_dp(0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}