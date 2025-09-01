#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

class DisjointSets {
  private:
    vector<int> parents;
    vector<int> sizes;

  public:
    DisjointSets(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }

    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }

        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

int d = -1, a;
void dfs(int depth, int u, int parent, vector<int> *tree) {
    for (int neighbour: tree[u]) {
        if (neighbour != parent) {
            dfs(depth + 1, neighbour, u, tree);
        }
    }
    if (d < depth) {
        d = depth;
        a = u;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges[i] = {c, --u, --v};
    }

    vector<int> tree[n];

    sort(begin(edges), end(edges));
    DisjointSets dsu(n);
    int count = 0; ll cost = 0;
    for (const auto &[w, u, v]: edges) {
        if (!dsu.connected(u, v)) {
            dsu.unite(u, v);
            tree[u].push_back(v);
            tree[v].push_back(u);
            cost += w * 1LL;
            ++count;
        }
    }

    dfs(0, 0, -1, tree);
    d = 0;
    dfs(0, a, -1, tree);
    cout << cost << '\n' << d;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}