#include <bits/stdc++.h>
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

int dp[2005][2005][2][2];
int m, d, mod = 1e9 + 7;
string a, b;

int solve(int i, int cnt, bool gta, bool ltb)
{
    if (i == a.size())
        return !cnt;
        
    int &x = dp[i][cnt][gta][ltb];
    if (x != -1)
        return x;
    x = 0;
    forj (10)
    {
        if (i % 2 && j != d || !(i % 2) && j == d)
            continue;
        if (!gta && a[i] - '0' > j || !ltb && b[i] - '0' < j)
            continue;
        bool na = gta | a[i] - '0' < j;
        bool nb = ltb | b[i] - '0' > j;
        x = (x + solve(i + 1, (cnt * 10 + j) % m, na, nb)) % mod;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> d >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0, 0);
}
