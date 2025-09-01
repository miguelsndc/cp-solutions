#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector<multiset<int>> tree(N + 1), g(N + 1);
    vector<int> deg(N + 1);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        deg[x]++, deg[y]++;
        tree[x].insert(y);
        tree[y].insert(x);
        g[x].insert(y);
        g[y].insert(x);
    }

    int Q; cin >> Q;

    set<pair<int,int>> s;
    for (int u = 1; u <= N; u++) {
        if (deg[u] == 1) {
            s.insert({deg[u], u});
        }
    }
    auto remove_edge = [&](int u, int v) {
        if (tree[u].find(v) != tree[u].end()) {
            tree[u].erase(tree[u].find(v));
        } 
        if (tree[v].find(u) != tree[v].end()) {
            tree[v].erase(tree[v].find(u));
        }
    };

    while (!s.empty()) {
        auto [degree, node] = *s.begin();
        s.erase(s.begin());
        if (degree > 1) break;
        int v = *tree[node].begin();
        remove_edge(node, v);
        deg[node]--; deg[v]--;
        if (deg[v] == 1) {
            s.insert({deg[v], v});
        }
    }

    int col = 1;
    vector<int> color(N + 1);
    auto dfs = [&] (auto && self, int u, int p = -1) -> void {
        color[u] = col;
        for (int x: g[u]) {
            if (deg[x] == 0 and x != p) {
                self(self, x, u);
            }
        }
    };

    for (int x = 1; x <= N; x++) {
        if (deg[x] != 0) {
            dfs(dfs, x);
            col++;
        }
    }

    while(Q--) {
        int x, y; cin >> x >> y;
        if (color[x] == color[y]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}