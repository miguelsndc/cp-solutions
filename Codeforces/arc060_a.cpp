#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
ll dp[51][2501];
void solve() {
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for (int &i : x) cin >> i;
    int sum = accumulate(all(x), 0);
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int c : x) {
        for (int j = N; j >= 1; j--) {
            for (int s = sum; s >= c; s--) {
                dp[j][s] += dp[j - 1][s - c];
            }
        }
    } 
    ll ans = 0;
    for (int t = 1; t <= N; t++) {
        int target = A * t;
        if (target <= sum) {
            ans += dp[t][target];
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}