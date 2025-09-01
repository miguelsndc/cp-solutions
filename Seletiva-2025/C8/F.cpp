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

int dp[105][105];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fori(105){
        forj(105){
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    string t; cin >> t;
    int n; cin >> n;
    fori(n) {
        forj(105) dp[i + 1][j] = dp[i][j];
        int m; cin >> m;
        while(m > 0) {
            m--;
            string s; cin >> s;
            for(int j = 0; j + s.size() <= t.size(); j++) {
                bool can = true;
                fork(s.size()) {
                    if (t[j + k] != s[k]) {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    dp[i + 1][j + s.size()] = min(dp[i+1][j+s.size()], dp[i][j] + 1);
                }
            }
        }
    }
    if(dp[n][t.size()] == (1e9)) dp[n][t.size()] = -1;
    cout << dp[n][t.size()] << "\n";
}