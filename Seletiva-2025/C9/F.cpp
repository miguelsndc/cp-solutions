#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
    #define int long long
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
       int n,m,d;cin>>n>>m>>d;
       vi v(n); fori(n) cin >> v[i]; 
       int ans = 0, sum = 0;
       set<pair<int, int>> s;
       fori(n) {
        int cur = sum + v[i] - d * (i + 1);
        ans = max(ans, cur);
        if (v[i] > 0) {
            s.insert({v[i], i});
            sum += v[i];
            if (s.size() >= m) {
                sum -= (s.begin()->first);
                s.erase(s.begin());
            }
        }
       }
       writeln(ans);
    }
    return 0;
}