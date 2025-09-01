#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M, X, Y;
        cin >> N >> M >> X >> Y;
        --X; --Y;

        vector<vector<int>> g(N);
        for (int i = 0; i < M; ++i) {
            int u, v; cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (auto &adj : g) sort(adj.begin(), adj.end());

        vector<int> path;
        vector<char> seen(N, 0);

        function<bool(int)> dfs = [&](int u) -> bool {
            path.push_back(u);
            seen[u] = 1;
            if (u == Y) return true;                 // first hit is lexicographically smallest
            for (int v : g[u]) {
                if (!seen[v]) {
                    if (dfs(v)) return true;         // bubble up success without backtracking
                }
            }
            seen[u] = 0;                              // backtrack
            path.pop_back();
            return false;
        };

        if (!dfs(X)) {
            cout << -1 << '\n';
        } else {
            for (int v : path) cout << v + 1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}
