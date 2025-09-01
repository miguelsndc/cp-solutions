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
    int n;cin>>n;
    vi v(n); rep(i,0,n)cin>>v[i];
    sort(begin(v), end(v));
    int q;cin>>q;
    rep(i,0,q){
        int m;cin>>m;
        int ub = upper_bound(begin(v),end(v), m) - begin(v);
        cout << ub << '\n';
    }
}