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
    ll mx = -1;
    rep(i,0,n) {
        rep(j,i,n) {
            rep(k,i,j+1) {
                v[k] = 1 - v[k];
            }

            ll cnt = 0;
            rep(k,0,n) {
                cnt += v[k];
            }

            rep(k,i,j+1) {
                v[k] = 1 - v[k];
            }

            mx = max(mx, cnt);
        }
    }
    cout << mx;
}