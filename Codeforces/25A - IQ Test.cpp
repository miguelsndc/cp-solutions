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
    vi ev, od;
    // wtf
    rep(i,1,n+1) {
        int x; cin>>x;
        if (x & 1) {
            od.push_back(i);
        } else {
            ev.push_back(i);
        }
    }
    if (od.size() == 1) cout << od[0];
    else cout<< ev[0];
}