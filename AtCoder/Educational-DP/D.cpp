#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;
i64 dp[105][maxn];

void solve() {
    int n, maxw;
    cin >> n >> maxw;
    memset(dp, 0, sizeof dp);
    vector<int> weight(105), value(105);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxw; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= weight[i - 1]) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
            }
        }
    }

    cout << dp[n][maxw];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}