#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[10000];
    memset(dp, -1, sizeof dp);
    dp[0]=0;
    rep(i,0,n) {
        if (dp[i] != -1) {
            dp[i + a] = max(dp[i + a], dp[i] + 1);
            dp[i + b] = max(dp[i + b], dp[i] + 1);
            dp[i + c] = max(dp[i + c], dp[i] + 1);
        }
    }
    cout << dp[n] ;
}