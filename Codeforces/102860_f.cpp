#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1); 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n + 1, false); 
    vector<int> colors;
    vector<pii> ans;
    map<int, int> tin; 
    int cnt = 1; 
    function<void(int, int)> dfs = [&](int u, int par) -> void {
        vis[u] = true;
        tin[u] = cnt++; 
        colors.push_back(u);
        for (int v : g[u]) {
            if (v == par) continue;
            if (!vis[v]) { 
                dfs(v, u);
                ans.push_back({tin[u], tin[v]});
            } else if (tin[u] > tin[v]) { 
                colors.push_back(u);          
                ans.push_back({tin[v], cnt}); 
                cnt++;                        
            }
        }
    };
    dfs(1, 0); 
    cout << cnt - 1 << '\n';
    for (int i = 0; i < colors.size(); ++i) { 
        cout << colors[i] << ' ';
    }
    cout << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T
    while(T--) solve();
    return 0;
}