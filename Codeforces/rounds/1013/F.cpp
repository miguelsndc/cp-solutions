#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
const int MOD = 998244353;
const int maxn = 2e3 + 5;

// row / col / f + 1 holds used
string s[maxn];
int dp[maxn][maxn][2];
// prefix sum
i64 sdp[maxn][maxn][2];
int n, m, d;

i64 getsum(int x, int y1, int y2, int f) {
    i64 u = sdp[x][y2][f];
    if (y1) u -= sdp[x][y1 - 1][f];
    return u;
}

int get (int i, int j, int f) {
    if (s[i][j] != 'X') return 0;
    i64 ans = 0;
    if (i == n - 1) ans++;

    if (!f) { // f == 0 exactly one hold
        ans += getsum(i, max(j - d, 0), min(m - 1, j + d), 1);
        ans -= dp[i][j][1];
    }

    if (i < n - 1) {
        ans += getsum(i + 1, max(0, j - d + 1), min(m - 1, j + d - 1), 0);
    }

    return ans % MOD;
} 

int main() 
{
    memset(dp, 0, sizeof dp);
    memset(sdp, 0, sizeof sdp);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        cin >> n >> m >> d;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int f = 1; f >= 0; f--) {
                for (int j = 0; j < m; j++) {
                    sdp[i][j][f] = dp[i][j][f] = get(i, j, f);
                }
                for (int j = 1; j < m; j++) {
                    sdp[i][j][f] += sdp[i][j - 1][f];
                }
            }
        }
        i64 ans = 0;
        for (int j = 0; j < m; j++){
            ans += dp[0][j][0];
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}