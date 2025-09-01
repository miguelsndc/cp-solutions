#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), dp(n + 1), ps(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + (a[i] < m);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int len = i - j;
            if ((ps[i] - ps[j]) < ((len + 1) / 2)) {
                if (j == 0) {
                    dp[i] = max(dp[i], 1);
                } else if (dp[j] > 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }
    cout << dp[n];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}