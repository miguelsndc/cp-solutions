#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
vector<vector<int>> g(mxn);
vector<int> curr_comp, visited(mxn);
vector<vector<int>> comps;
void dfs(int u) {
    visited[u] = true;
    curr_comp.push_back(u);
    for (int v: g[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            curr_comp.clear();
            dfs(i);
            comps.push_back(curr_comp);
        }
    }

    vector<pair<int,int>> ans;
    for (int i = 1; i < comps.size(); i++) {
        vector<int> &cp = comps[i];
        vector<int> &cp_prev = comps[i - 1];
        ans.push_back({cp[0] + 1, cp_prev[0] + 1});
    }

    cout << ans.size() << '\n';
    for (auto[x, y]: ans) {
        cout << x << ' ' << y << '\n';
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
