#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define fork(n) for (int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' ';
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<ii> v(n);
    fori(n) cin >> v[i].first >> v[i].second;
    map<int, int> cnt;
    ll c = 0;
    for (const auto &[x, y] : v)
    {
        if (cnt[x] == 1)
        {
            c += n - 2;
        }
        cnt[x]++;
    }
    set<ii> s{v.begin(), v.end()};
    for (const auto &[x, y] : s)
    {
        if (s.count({x - 1, 1 - y}) and s.count({x + 1, 1 - y}))
        {
            c++;
        }
    }
    writeln(c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}