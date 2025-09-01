#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int R, C; cin >> R >> C;
    vector grid(R, vector<int>(C));
    int K; cin >> K;
    while(K--) {
        int i, j; cin >> i >> j;
        grid[--i][--j] = 1;
    }
    vector dp(R + 1, vector<int>(C + 1));
    dp[1][1] = (grid[0][0] == 0);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (grid[i - 1][j - 1]) continue;
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    cout << dp[R][C] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}