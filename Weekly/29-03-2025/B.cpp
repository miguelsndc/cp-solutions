#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int maxn = 1e5 + 5;

int n; string s;
int dp[maxn][4];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; cin >> s;
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][2], dp[i][3]) + (s[i] == 'W' or s[i] == 'E');
        dp[i + 1][1] = max(dp[i][2], dp[i][3]) + (s[i] == 'W' or s[i] == 'E');
        dp[i + 1][2] = max(dp[i][0], dp[i][1]) + (s[i] == 'N' or s[i] == 'S');
        dp[i + 1][3] = max(dp[i][0], dp[i][1]) + (s[i] == 'N' or s[i] == 'S');
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
}