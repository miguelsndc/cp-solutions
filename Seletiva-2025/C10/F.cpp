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
    int n; cin >> n;
    vector<vi> mat(10, vi(10));
    fori(n) forj(n) cin >> mat[i][j];
    int dp[(1 << 10)];
    memset(dp, 0, sizeof dp);
    for (int mask = 0; mask < (1<<n); mask++) {
        int cnt = __builtin_popcount(mask);
        for (int s = 0; s < n; s++) {
            if (mask & (1 << s)) {
                dp[mask] = max(dp[mask], dp[mask ^ (1 << s)] + mat[s][cnt - 1]);
            }
        }
    }
    cout << dp[(1 << n) - 1];
}