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

ll solve(ll a, ll b, ll c) {
    ll l = 0, r = 600000001;
    while ((r - l) > 1) {
        ll m = l + (r - l) / 2;
        if (a * m * m + b * m + c <= 0) {
            l = m;
        } else {
            r = m;
        }
    }
    if (a * l * l + b * l + c == 0) {
        return l;
    }
    return -1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    for (ll d = 1; d * d * d <= n; d++) {
        if (n % d != 0) continue;
        ll m = n / d;
        ll k = solve(3, 3*d, d*d - m);
        if (k > 0) {
            write(k + d); write(k);
            return 0;
        }
    }
    write(-1);
}