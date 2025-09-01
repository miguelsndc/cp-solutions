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

vi g[maxn]; vector<ll> cnt(maxn);
void dfs(int u, int p) {
    if (g[u].size() == 1 and g[u][0] == p) {
        cnt[u] = 1;
    }
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

void solve() {
    int n; cin >> n;
    fori(n + 1) {
        g[i + 1].clear();
    }
    fori(n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt.assign(n + 1, 0);
    dfs(1, 0);
    ll q; cin >> q;
    fori(q) {
        int x, y; cin >> x >> y;
        writeln(cnt[x] * cnt[y]);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
}