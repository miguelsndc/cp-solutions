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

ll prod(ll x) {
    ll p = 1;
    while(x>0) {
        p *= x % 10;
        x/=10;
    }
    return p;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b; cin >> a >> b;
    string sa = to_string(a);
    string sb = to_string(b);
    ll ans = b;
    rep (i,0,sb.size()) {
        if (sb[i] == '0') continue;
        string aux = sb;
        string curr = sb;
        curr[i] = ((curr[i] - '0') -1) + '0';
        rep(j,i+1,curr.size()) curr[j]='9';
        ll num=0;
        rep(j,0,curr.size()){
            num = num * 10 + (curr[j] - '0');
        }
        if (num >= a && prod(ans) < prod(num)){
            ans=num;
        }
    }
    cout << ans;
}