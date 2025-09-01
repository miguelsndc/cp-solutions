#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009
#define vi vector<int>
#define pii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    vi h(n + 1), dp(n + 1, INT32_MIN);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1] + h[i]);
        if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + h[i]);
    }
    cout << dp[n];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("ladder");
    #endif
    int tt = 1;
    while(tt--) {
         solve();
    }
}