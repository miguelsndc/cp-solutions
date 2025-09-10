#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}
void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int dp[n][2];
    memset(dp, -1, sizeof dp);
    function<int(int, bool)> dfs = [&](int i, bool c) -> int {
        if (i >= n) return 0;
        if (dp[i][c] != -1) return dp[i][c];
        int ans = 1e9 + 1;
        if (c) {
            int l  = a[i] + dfs(i + 1, c ^ 1), r = 1e9 + 1;
            if (i + 1 < n) r = a[i] + a[i + 1] + dfs(i + 2, c ^ 1);
            ans = min(l, r);
        } else {
            ans = min(dfs(i + 1, c ^ 1), dfs(i + 2, c ^ 1));
        }
        return dp[i][c] = ans;
    };

    cout << dfs(0, 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}