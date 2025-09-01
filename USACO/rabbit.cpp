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
    string s; cin >> s;
    vi dp(n + 1, INT32_MIN);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int grass = (s[i - 1] == '"');
        int swamp = (s[i - 1] == 'w');

        if (swamp) continue;
        
        dp[i] = max(dp[i], dp[i - 1] + grass);
        if(i >= 4) dp[i] = max(dp[i], dp[i - 3] + grass);
        if (i >= 6) dp[i] = max(dp[i], dp[i - 5] + grass);
    }
    cout << (dp[n] < 0 ? -1 : dp[n]);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("lepus");
    #endif
    int tt = 1;
    while(tt--) {
         solve();
    }
}