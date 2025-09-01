#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    // menor numero de elementos pra remover ate i
    vector<int> dp(n, n + 1), a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto get =[&](int pos) {
        if (pos > n) {
            return n + 1;
        } else if (pos == n) {
            return 0;
        }
        return dp[pos];
    };
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        // 
        // remove esse cara ou o resto dps do range dele
        dp[i] = min(dp[i + 1] + 1, get(i + a[i] + 1));
    }
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}