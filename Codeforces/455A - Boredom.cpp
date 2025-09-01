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

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int maxn=1e5+5;
    vector<ll> cnt(maxn), dp(maxn);
    int n; cin >> n;
    rep(i,0,n) {
        int x;cin>>x;
        cnt[x]++;
    }
    dp[1] = cnt[1];
    rep(i, 2, 100001) {
        dp[i] = max(dp[i - 1], cnt[i] * i + dp[i - 2]);
    }
    cout << dp[100000];
}