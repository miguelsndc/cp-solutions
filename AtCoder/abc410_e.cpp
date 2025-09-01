#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}

template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}

void solve() {
    int n, h, m;
    cin >> n >> h>> m;
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= m; i++) {
        dp[0][i] = h;
    }
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= m; j++) {
            chmax(dp[i][j], dp[i - 1][j] - a);
            if (j + b <= m) {
                chmax(dp[i][j], dp[i - 1][j + b]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] >= 0) {
                ok = true;
                break;
            }
        }
        if (ok)
            ans++;
        else
            break;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}