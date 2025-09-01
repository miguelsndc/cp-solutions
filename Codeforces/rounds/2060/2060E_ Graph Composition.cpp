#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int MAXN = 2e5 + 5;

struct DisjointSet {
    int parents[MAXN];
    int sizes[MAXN];

    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    
    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
    
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true; // (some condition met for component);
    }
};
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    DisjointSet dsg(n), dsf(n);
    // edges of f
    int ans = 0;
    vector<ii> edges_f(m1), edges_g(m2);
    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        edges_f[i] = {u, v};
    }
    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        edges_g[i] = {u, v};
    }

    for (const auto&[u, v] : edges_g) {
        dsg.unite(u, v);
    }
    
    for (const auto&[u, v] : edges_f) {
        if (dsg.find(u) != dsg.find(v)) {
            ans++;
        } else {
            dsf.unite(u, v);
        }
    }

    for (const auto&[u, v] : edges_g) {
        if (dsf.find(u) != dsf.find(v)) {
            ans++;
        }
        dsf.unite(u, v);
    }
    cout << ans << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}