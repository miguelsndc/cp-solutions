#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
void solve() {
    std::ifstream read("fenceplan.in");
    int n, m; read >> n >> m;
    vector<pair<int,int>> coords(n);
    for (int i = 0; i < n; i++) {
        read >> coords[i].x >> coords[i].y;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v; read >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> curr, visited(n);
    vector<vector<int>> comps;
    auto dfs = [&](auto &&self, int u) -> void {
        curr.push_back(u);
        visited[u] = true;
        for (int v: g[u]) {
            if (!visited[v]) {
                self(self, v);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            curr.clear();
            dfs(dfs, i);
            comps.push_back(curr);
        }
    }

    ll min_size = 1e18;
    for (int i = 0; i < comps.size(); i++) {
        if (comps[i].size() == 1) {
            min_size = 0;
        } else {
            int minx = 1e9, maxx = -1, miny = 1e9, maxy = -1;
            for (int node: comps[i]) {
                minx = min(minx, coords[node].x);
                miny = min(miny, coords[node].y);
                maxx = max(maxx, coords[node].x);
                maxy = max(maxy, coords[node].y);
            }
            int dx = maxx - minx;
            int dy = maxy - miny;
            ll perim;
            if (dx == 0) {
                perim = dy;
            } else if (dy == 0) {
                perim = dx;
            } else {
                perim = 2 * dx + 2 * dy;
            }
            min_size = min(min_size, perim);
        }
    }
    std::ofstream("fenceplan.out") << min_size;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
