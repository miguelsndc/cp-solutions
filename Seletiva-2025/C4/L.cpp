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

vi g1[1001], g2[1001], sz(1001), vis(1001);
int n, k; 

int dfs1(int u, int par) {
    sz[u] = 1;
    if (g1[u].empty()) return sz[u];
    vector<ii> sub;
    for (int v: g1[u]) {
        if (v != par) {
            int child_sub = dfs1(v, u);
            sub.push_back({child_sub, v});
        }
    }
    sort(begin(sub), end(sub), greater<ii>());
    if (sub.size() >= k) {
        fori(k) {
            sz[u] += sub[i].fi;
            int child = sub[i].se;
            g2[child].push_back(u);
            g2[u].push_back(child);
        }
    }
    return sz[u];
}

int dfs(int u) {
    vis[u] = true;
    int cnt = 1;
    for(int v: g2[u]) {
        if (!vis[v]) {
            cnt += dfs(v);
        }
    }
    return cnt;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        fori(n - 1) {
            int u, v; cin >> u >> v;
            g1[u].push_back(v);
            g1[v].push_back(u);
        }

        dfs1(1, -1);
        int ans = dfs(1);
        cout << "Case " << tt << ": " << ans << '\n';

        fori(1001) {
            g1[i].clear();
            g2[i].clear();
            vis[i] = false;
        }

        int a = 2;
    }
}
