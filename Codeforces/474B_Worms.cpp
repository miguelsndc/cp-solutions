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
    int s=0;
    vi v(n); rep(i,0,n)cin>>v[i], s+=v[i];
    vi ps(n+1); ps[0]=0;
    rep(i,0,n)ps[i+1]+=ps[i]+v[i];
    vi mp((1e6 + 5));
    int k=1;
    repi(i,1,n){
        repi(j,ps[i-1]+1,ps[i]) {
            mp[j]= k;
        }
        k++;
    }
    int q;cin>>q;
    rep(i,0,q) {
        int x;cin>>x;
        cout <<mp[x]<<'\n';
    }
}