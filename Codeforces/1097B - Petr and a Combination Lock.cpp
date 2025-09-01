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

int n, mod = 360; 
vi v(15);
bool f(int i, int deg) {
    if (i == n) return deg == 0;
    bool left = f(i + 1, (mod + (deg - v[i]) % mod) % mod);
    bool right = f(i + 1, (deg + v[i]) % mod);
    return (left || right);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fori(n)cin>>v[i];
    cout << ((f(0, 0) ? "YES" : "NO"));
}