#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        ll n, l, r; cin >> n >> l >> r;
        vi a(n + 1), pref(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
        // add a[(n + 1) / 2]
        if (n % 2 == 0) {
            n++;
            int cur = pref[n / 2] & 1;
            a.push_back(cur);
            pref.push_back(pref.back() + cur);
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            a.push_back(pref[i / 2] & 1);
            pref.push_back(pref[i - 1] + a[i]);
        }
        int p = pref[n] & 1;
        function<ll(ll)> query = [&](ll x) {
            ll ret = 0;
            while(1) {
                if (x <= 2 * n) {
                    ret ^= a[x];
                    break;
                }
                ret ^= p;
                if ((x/2 - n) % 2 == 0) {
                    break;
                }
                x/=2;
            }
            return ret;
        };
        writeln(query(l));
    }
}