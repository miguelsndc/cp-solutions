#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 505 + 5;

vector<int> g[maxn], revg[maxn];
vector<bool> vis(maxn), comp(maxn);

// kosaraju dfs
void dfs(int node, vector<int> *graph, vector<int> & output, vector<bool> &check) {
    vis[node] = true;
    for (int v: graph[node]) {
        if (!vis[v]) dfs(v, graph, output, check);
    }
    check[node] = true;
    output.push_back(node);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].resize(n);
        for (int j = 0; j < n; j++) cin >> g[i][j];
        while(g[i].back() != i) g[i].pop_back();
        for (int x: g[i]) {
            revg[x].push_back(i);
        }
    }
    vector<int> order;

    //kosaraju
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, g,order, comp);
    }

    reverse(order.begin(), order.end());
    vis.assign(n, false), comp.assign(n, false);

    vector<int> ans(n + 1);
    for (int i: order) {
        if (!vis[i]) {
            vector<int> scc;
            dfs(i, revg, scc, comp);
            // in the scc
            for (int j: scc) {
                for (int k: g[j]) {
                    // if its also in the component
                    if (comp[k]) {
                        ans[j] = k;
                        break;
                    }
                }
            }

            comp.assign(n, false);
        }
    }

    for (int i = 1;i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}