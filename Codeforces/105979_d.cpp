#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

struct UnionFind {
    vector<int> parents, sizes;

    // O(n)
    UnionFind(int n) {
        parents.assign(n, 0);
        sizes.assign(n, 1);
        iota(all(parents), 0);
    }

    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return false;
        }
        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;  // (some condition met for component);
    }
};

const int maxn = 1e6 + 10;
void solve() {
    int n, m;
    cin >> n >> m;
    vc<int> energy(n);
    for (int i = 0; i < n; i++) cin >> energy[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    UnionFind dsu(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {energy[i], i};
    sort(all(a));
    vector<int> ans(n), done(n);
    for (int i = 0; i < n; i++) {
        int e = a[i].first, u = a[i].second;
        int j = i;
        while (j < n and a[j].first == e and !done[j]) {
            done[j] = true;
            for (int v : g[a[j].second]) {
                if (energy[v] <= e) {
                    dsu.unite(a[j].second, v);
                }
            }
            j++;
        }
        ans[u] = dsu.sizes[dsu.find(u)];
    }
    for (int v : ans) {
        cout << v << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}