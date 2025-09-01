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
    int tc = 1;
    while(tc--) {
        int n; cin >> n;
        vector<ll> sortedv(n), v(n);
        rep(i,0,n) {
            cin >> v[i];
            sortedv[i] = v[i];
        }
        sort(begin(sortedv), end(sortedv));
        vector<ll> sorted_ps(n + 1), ps(n + 1);
        rep(i,0,n) {
            ps[i + 1] = ps[i] + v[i];
            sorted_ps[i + 1] = sorted_ps[i] + sortedv[i];
        }
        int q; cin >> q;
        while(q--) {
            int type, l, r; cin >> type >> l >> r;
            if (type == 2) {
                cout << sorted_ps[r] - sorted_ps[l - 1] << '\n';
            } else {
                cout << ps[r] - ps[l - 1] << '\n';
            }
        }
    }
}