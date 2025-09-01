#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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
    int tc; cin >> tc;
    while(tc--) {
        int n, l, r; cin>>n>>l>>r;
        vi v(n); rep(i,0,n)cin>>v[i];
        sort(begin(v), end(v));
        ll cnt = 0;
        rep(i,0,n) {
            cnt += upper_bound(v.begin(), v.end(), r - v[i]) - begin(v);
            cnt -= lower_bound(v.begin(), v.end(), l - v[i]) - begin(v);
            if (l <= 2 * v[i] && 2 * v[i] <= r) { // v[i] with itself does not count
                cnt--;
            }
        }
        cout << (cnt >> 1) << '\n';
    }
}