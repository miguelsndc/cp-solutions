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
int sz[maxn];
vector<int> g[maxn];
int n, k;
void dfs(int u, int p, int t) {
    if (t == 0) {
        for (int v: g[u]) {
            if (v != p) {
                dfs(v, u, 0);
            }
        }
        dfs(u, p, 1);
    } else {
        int cnt = 0;
        for (int v: g[u]) {
            if (v != p) {
                sz[u] += sz[v];
                if (sz[v] > 0) {
                    cnt += 1;
                }
            }
        }
        if (sz[u] > k or cnt > 2) {
            writeln("No");
            exit(0);
        }
        if (sz[u] < k and cnt > 1) {
            writeln("No");
            exit(0);
        }
        if (sz[u] == k) {
            sz[u] = 0;
        }
    }
}

int main() 
{
    fori(maxn) sz[i] = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin >> n >> k;
    fori(n * k - 1) {
        int u, v; cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, 0);
    writeln("Yes");
}