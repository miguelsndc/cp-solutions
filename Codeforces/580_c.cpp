#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> cat(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> cat[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    int ans = 0;
    auto dfs = [&](auto &&f, int u, int p, int cnt) {
        if (cnt > m) return;
        for (int v: g[u]) {
            if (v == p) continue;
            f(f, v, u, cnt * cat[u] + cat[v]);
        }
        if (g[u].size() == 1 and g[u].back() == p)ans++;
    };

    dfs(dfs, 0, -1, cat[0]);

    cout << ans << '\n';
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
