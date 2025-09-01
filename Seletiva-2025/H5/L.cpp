#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<array<int, 4>> g(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        g[i] = {a, b, c, d};
    }
    vector<set<int>> dp(n + 1, set<int>{});
    dp[0].insert(x);
    for (int i = 0; i < n; i++) {
        for (int v: dp[i]) {
            if (v >= x - k) {
                int diff = (g[i][3] ? (v + g[i][0]) : (v - g[i][1]));
                dp[i + 1].insert(diff);
            }
            if (v <= x + k) {
                int diff = (g[i][2] ? (v + g[i][0]) : (v- g[i][1]));
                dp[i + 1].insert(diff);
            }
        }
    }

    int ans = INT32_MIN;
    for (int v: dp[n]) {
            ans = max(ans, v);
        }
    cout << ans;
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