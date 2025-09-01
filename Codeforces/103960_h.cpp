#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> visited;
void dfs(int v, vector<vector<int>> &adj, vector<int> &output) {
    visited[v] = true;
    for (auto u: adj[v]) {
        if (!visited[u]) dfs(u, adj, output);
    }
    output.push_back(v);
}
int scc(vector<vector<int>> & adj, vector<vector<int>> &adj_transp) {
    int n = adj.size();
    vector<vector<int>> components; 
    vector<int> order, root(n, 0);
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if(!visited[i]) dfs(i, adj, order);
    }
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    for (int v: order) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj_transp, component);
            components.push_back(component);
            int rt = *min_element(component.begin(), component.end());
            for (int u: component) {
                root[u] = rt;
            }
        }
    }
    vector<int> in_deg(n, 0), out_deg(n, 0);
    for (int v = 0; v < n; v++) {
        for (auto u: adj[v]) {
            if (root[v] != root[u]) {
                out_deg[root[v]]++;
                in_deg[root[u]]++;
            }
        }
    }
    set<int> s1, s2;
    for (int i = 0; i < n; i++) {
        if (in_deg[root[i]] == 0) {
            s1.insert(root[i]);
        }
        if (out_deg[root[i]]==0) {
            s2.insert(root[i]);
        }
    }
    int c = components.size();
    return (c == 1 ? 0 : max(s1.size(), s2.size()));
}
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), adj_transp(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj_transp[v].push_back(u);
    }
    int ans = scc(adj, adj_transp);
    cout << ans << '\n';
}
int main() {
    int T = 1; // cin >> t;
    while(T--) solve();
}