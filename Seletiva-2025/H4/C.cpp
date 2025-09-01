#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

class DSU {
  private:
    vector<int> parents;
    vector<int> sizes;

  public:
    DSU(int size) : parents(size), sizes(size, 1) {
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

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    DSU dsu(n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = {c, --a, --b};
    } 

    sort(begin(edges), end(edges));

    ll min_cost = 0, edges_count = 0;
    for (const auto &[w, a, b]: edges) {
        if (!dsu.connected(a, b)) {
            dsu.unite(a, b);
            min_cost += w;
            edges_count++;
        }
    }
    if (edges_count == n - 1) {
        cout << min_cost;
    } else {
        cout << "IMPOSSIBLE";
    }
}