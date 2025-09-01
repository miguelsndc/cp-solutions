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
    int n,m;cin>>n>>m;
    vector<vi> ans = {{}};
    repi(i,1,n) {
        vector<vi> v;
        for (vi a: ans) {
            repi(x,(i==1?1:a.back()+10),m-10*(n-i)) {
                vi a2 = a;
                a2.push_back(x);
                v.push_back(a2);
            }
        }
        swap(v,ans);
    }
    cout<<ans.size()<<'\n';
	rep(i,0,ans.size()) rep(j,0,n) cout << ans[i][j] << " \n"[j == n - 1];
}