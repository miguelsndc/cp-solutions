#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<i64> h(n + 1), dp(n + 1, inf);
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == inf) continue; // havent reached
        for (int j = 1; j <= k && (i + j <= n); j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }
    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}