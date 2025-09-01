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
    vi a(n),b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    sort(a.begin(), a.end());

    rep(i,0,m) {
        int v = b[i];
        cout << upper_bound(begin(a), end(a), b[i]) - begin(a) << ' ';
    }
}