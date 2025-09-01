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
    int n,time;cin>>n>>time;
    vi v(n), ps(n + 1);
    rep(i,0,n) cin>> v[i];
    rep(i,0,n) ps[i + 1] = ps[i] + v[i];
    int l = 0, r = 0, mx = 0;
    while(r <= n && l <= r) {
        if (ps[r] - ps[l] <= time) {
            mx = max(mx, r - l);
            r++;
        } else {
            l++;
        }
    }
    cout << mx;
}