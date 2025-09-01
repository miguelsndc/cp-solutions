#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

 
#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second
#define oset tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update> 

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    //abusrdamente util
    oset s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert({v[i], i});
    }
    while(q--) {
        char type; cin >> type;
        if (type == '!') {
            int k, x; cin >>  k >> x;
            --k;
            s.erase({v[k], k});
            v[k] = x;
            s.insert({v[k], k});
        } else {
            // for (ii x: s) {
            //     cout <<'(' << x.fi << ", " << x.se << ") ";
            // }
            // cout << '\n';
            const int INF = 1e9 + 9;
            int a, b; cin >> a >> b;
            int ub = s.order_of_key({b, INF});
            int lb = s.order_of_key({a - 1, INF});
            cout << ub - lb << '\n';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}