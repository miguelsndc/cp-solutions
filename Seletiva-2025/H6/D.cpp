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
    while(tc--) {
        int n; cin >> n;
        ll mat[n][n], dp[(1 << n)][n];
        memset(mat, 0, sizeof mat);
        fill(&dp[0][0], &dp[0][0] + (1 << n) * n, LLONG_MAX);
        fori(n) forj(n) cin >> mat[i][j];
        dp[1][0] = 0;
        fork((1 << n)) {
            fori(n) {
                if (dp[k][i] == LLONG_MAX) continue;
                forj(n) {
                    if ((k & (1 << j)) == 0) {
                        dp[(k | (1 << j))][j] = min(dp[(k | (1 << j))][j], dp[k][i] + mat[i][j]);
                    }
                }
            }
        }
        ll ans = LLONG_MAX;
        for(int i = 1; i < n; i++) {
            if (dp[(1 << n) - 1][i] != LLONG_MAX) {
                ans = min(ans, dp[(1 << n) - 1][i] + mat[i][0]);
            }
        }
        writeln(ans);
    }
}