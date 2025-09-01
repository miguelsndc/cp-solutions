#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    int s, k; cin >> s >> k;
    if (s % k == 0) {
        cout << k << '\n';
        return;
    } 
    if (s > k * k) {
        cout << max(1, k - 2) << '\n';
        return;
    }

    vector<bool> dp(s + 1);
    dp[0] = 1;
    while(1) {
        vector<bool> ndp(s + 1);
        // going forward
        for (int i = k; i <= s; i++) ndp[i] = dp[i - k] || ndp[i - k];
        dp = ndp;
        if (dp[s]) {
            cout << k << '\n';
            return;
        }
        // if cant reach with full power, reduce
        k = max(1, k - 1);
        ndp = vector<bool>( s+ 1);
        // see reachable backward positions
        for (int i = s - k; i >= 0; i--) ndp[i] = dp[i + k] || ndp[i + k];
        dp = ndp;
        // swap again and try a smaller power
        k = max(1, k - 1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}