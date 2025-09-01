#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n, k; cin >> n >> k;
    vi h(n + 1), dp(n + 1, INT32_MAX);
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 1) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
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