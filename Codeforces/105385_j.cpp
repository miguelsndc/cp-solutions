#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define all(x) (x).begin(), (x).end()

struct UnionFind {
    vector<int> pai, sz;
    UnionFind(int n) {
        pai.assign(n, 0);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) pai[i] = i;
    }
    int find(int x) { return pai[x] == x ? x : (pai[x] = find(pai[x])); }
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (sz[xr] < sz[yr]) swap(xr, yr);
        sz[xr] += sz[yr];
        pai[yr] = xr;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(n);
    for (int i = 0; i < n; i++) cin >> cnt[i];
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<tuple<int, int, int>> arestas;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            arestas.push_back({mat[i][j], i, j});
    sort(arestas.begin(), arestas.end());

    UnionFind uf(n);
    vector<bool> conectado(n);
    for (int i = 0; i < n; i++) conectado[i] = (cnt[i] == 1);
    ll ans = 0;
    for (auto [w, u, v] : arestas) {
        if (u == v) {
            if (!conectado[u]) {
                ans += (cnt[u] - 1) * w;
                conectado[u] = true;
            }
        } else {
            if (uf.find(u) != uf.find(v)) {
                if (!conectado[u] && !conectado[v]) {
                    ans += (cnt[u] + cnt[v] - 1) * w;
                    conectado[u] = conectado[v] = true;
                } else if (!conectado[u]) {
                    ans += cnt[u] * w;
                    conectado[u] = true;
                } else if (!conectado[v]) {
                    ans += cnt[v] * w;
                    conectado[v] = true;
                } else {
                    ans += w;
                }
                uf.unite(u, v);
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}