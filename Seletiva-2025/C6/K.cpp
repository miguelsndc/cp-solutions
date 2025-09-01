#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n + 1, vector<char>(n + 1, '*'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i + 1][j + 1];
        }
    }

    vector<vi> dp(n + 1, vi(n + 1));
    dp[n][n] = grid[n][n] == '.';
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (grid[i][j] != '*') {
                if (i + 1 <= n) {
                    dp[i][j] = (dp[i][j] % MOD + dp[i + 1][j] % MOD) % MOD;
                }
                if (j + 1 <= n) {
                    dp[i][j] = (dp[i][j] % MOD + dp[i][j + 1] % MOD) % MOD;
                }
            }
        }
    }
    cout << dp[1][1];
    return 0;
}