#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, X; cin >> N >> X;
    vector dp(4, vector<int> (X + 1));
    for (int i = 1; i <= N; i++) {
        int v, a, c; cin >> v >> a >> c;
        for (int j = X; j >= c; j--) {
            dp[v][j] = max(dp[v][j], dp[v][j - c] + a);
        }
    }
    int ans = 0;
    for (int i = 0; i <= X; i++) {
        for (int j = 0; j + i <= X; j++) {
            int k = X - (i + j);
            ans = max(ans, min({dp[1][i], dp[2][j], dp[3][k]}));
        }
    }
    cout << ans;
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}