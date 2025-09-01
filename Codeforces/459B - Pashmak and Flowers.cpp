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
    ll n;cin>>n;
    vi v(n);rep(i,0,n)cin>>v[i];
    /*
    calculate difference between every pair of numbers
    output maximum difference and the number of pairs that satisfy that:
    */

    sort(begin(v), end(v));
    ll maxdiff = v[n - 1] - v[0];
    if (maxdiff == 0) {
        cout << 0 << ' ' << n * (n - 1) / 2;
        return 0;
    }
    ll mn = count(begin(v), end(v), v[0]); 
    ll mx = count(begin(v), end(v), v[n-1]); 
    cout << maxdiff << ' ' << mn * mx;
}