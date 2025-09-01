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
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;

    int dp[maxn];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= maxn; i++) {
        int k = i;
        int sum = 0;    
        while (k) {
            sum += k % 10;
            k /= 10;
        }
        dp[i] = dp[i - 1] + sum;
    }
    // 

    while(tc--) {
        int n; cin >> n;
        writeln(dp[n]);
    }
}