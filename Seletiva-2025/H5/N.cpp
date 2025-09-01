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

const int maxn = 301;
double dp[maxn][maxn][maxn];

int n; 
double f(ll x, ll y, ll z) {
    if (x == 0 and y == 0 and z == 0) return 0;
    if (x < 0 or y < 0 or z < 0) return 0;
    if (dp[x][y][z] > -0.9) return dp[x][y][z];
    double t1 = f(x - 1, y, z)*(double)x;
    double t2 = f(x + 1, y - 1, z)*(double)y;
    double t3 = f(x, y + 1, z - 1)*(double)z;
    return dp[x][y][z] = (n + t1 + t2 + t3) / (x + y + z);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof dp);
    vector<ll> v(n), a(4);
    fori(n) {
        cin >> v[i];
        a[v[i]]++;
    }
    cout << setprecision(20) << fixed << f(a[1], a[2], a[3]);
}