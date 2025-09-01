#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector<ll> h(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        vector<int> p;
        for (int i = 2; i <= n - 1; i++) {
            if (h[i] < h[i - 1] && h[i] < h[i + 1]) {
                p.push_back(i);
            }
        }
        int m = p.size();
        if (m == 0) {
            cout << 0 << '\n';
            continue;
        }
        vector<ll> dp(m + 1, 0);
        for (int k = 1; k <= m; k++) {
            int i = p[k - 1];
            ll c = max(0LL, min(h[i - 1], h[i + 1]) - h[i]) * x;
            dp[k] = dp[k - 1] + c;
            if (i - 1 >= 1) {
                dp[k] = min(dp[k], dp[k - 1] + max(0LL, h[i - 1] - h[i]) * y);
            }
            if (i + 1 <= n) {
                dp[k] = min(dp[k], dp[k - 1] + max(0LL, h[i + 1] - h[i]) * y);
            }
            if (k >= 2 && p[k - 1] == p[k - 2] + 2) {
                int j = p[k - 2] + 1;
                ll cost = max(0LL, h[j] - min(h[p[k - 2]], h[p[k - 1]])) * y;
                dp[k] = min(dp[k], dp[k - 2] + cost);
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}