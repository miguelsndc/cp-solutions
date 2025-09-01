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
    int tc; cin >> tc;
    while(tc--) {
        int n;cin>>n;
        vector<ll> v(n);
        rep(i,0,n)cin>>v[i];
        ll sum = 0;
        int l = 0, r = 0, positive = v[0] >= 0;
        while(r < n) {
            ll mx = INT32_MIN;
            while(r < n && v[r] * v[l] > 0) {
                mx = max(mx, v[r]);
                r++;
            }
            l = r;
            sum += mx;
        }
        cout << sum << '\n';
    }
}