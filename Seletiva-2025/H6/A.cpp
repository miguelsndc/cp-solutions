#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 2e5 + 5;

ll dp[1000002][2];
int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0, sizeof dp);
    dp[1][1] = 1;
    dp[1][0] = 1;
    for (int i = 1; i < 1000000; i++) {
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i+1][0] += 2*dp[i][0];
        dp[i+1][1] += dp[i][0];
        dp[i+1][0] += dp[i][1];
        dp[i+1][1] += 4*dp[i][1];
    }

    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ll ans = dp[n][0] + dp[n][1];
        ans %= MOD;
        cout << ans << '\n';
    }
}