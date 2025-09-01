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

void solve() {
    int n,s,e;cin >> n >> s >> e;
    vi g[n + 1];
    fori(n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    /*
    enraiza arvore no end
    dai se vc andar na direçao dos nos com profundidade maxima n
    dps os nos com profundidade n - 1, n- 2, etc até 1 vc termina chegando
    na raiz dnv
    dai itera ao contrario pra pegar a ordem inversa (terminando no fim ao inves de comelar)
    */

    vi depth(n + 1);
    vi a[n + 1];
    function<void(int, int)> dfs = [&](int u, int par) {
        depth[u] = depth[par] + 1;
        a[depth[u]].push_back(u);
        for (int v: g[u]) {
            if (v != par) {
                dfs(v, u);
            }
        }
    };

    dfs(e, 0);
    for (int i = n; i > 0; i--) {
        // start at max depth e aumenta ate chegar na profundadide 1 (raiz i.e end)
        for (int j: a[i]) {
            write(j);
        }
    }
    writeln("");
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