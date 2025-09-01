#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

/*
    Disjoint Set Union with path compression
    Complexidade:
        - find(u) O(alpha(n))
        - unite(u) O(alpha(n))
*/

struct UnionFind {
    vector<int> par, sz;

    // O(n)
    UnionFind(int n) {
        par.assign(n, 0);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    // O(alpha(n)) ~ O(1)
    int find(int x) { return par[x] == x ? x : (par[x] = find(par[x])); }

    // O(alpha(n)) ~ O(1)
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
        sz[x_root] += sz[y_root];
        par[y_root] = x_root;
        return true;  // (some condition met for component);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges[i] = {w, --u, --v};
    }

    UnionFind dsu(n);
    sort(all(edges));
    ll cost = 0, cnt = 0;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            cost += w;
            cnt++;
        }

        if (cnt == (n - 1)) {
            cout << cost << '\n';
            return;
        }
    }

    cout << "IMPOSSIBLE";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}