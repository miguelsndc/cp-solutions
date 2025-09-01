#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, K;
    cin >> N >> K;
    // how many ways can i get sum N using K pieces
    /*
        at sum i and at piece x and used j pieces
        reach: sum + x using j + 1 += sum j
        f(sum + x, j + 1) += f(sum, j)
    */
    vector dp(N + 1, vector<int>(K + 1));
    dp[0][0] = 1;
    for (int x = 1; x <= N; x++) {
        for (int sum = 0; sum + x <= N; sum++) {
            for (int i = 0; i < K; i++) {
                if (sum + x <= N and dp[sum][i] != 0) {
                    dp[sum + x][i + 1] += dp[sum][i];
                }
            }
        }
    }
    cout << dp[N][K] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}