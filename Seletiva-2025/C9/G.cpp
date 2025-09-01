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
#define debug(x) cout << #x << " is: " << x << "\n";
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        vi v(n); rep(i,0,n) cin >> v[i];
        vector<ll> ps(n + 1);
        rep(i,0,n) ps[i+1]=ps[i]+v[i];
        while(m--) {
            ll sd, sm, ed, em; cin >> sd>>sm>>ed>>em;
            ll year = ps[n];
            ll end = ps[em - 1] + ed;
            ll start = ps[sm - 1] + sd;
            if (end >= start) {
                cout << end - start + 1 << '\n';
            } else {
                cout << year - start + end + 1 << '\n';
            }
            // wraps year and ends back
        }
    }
}