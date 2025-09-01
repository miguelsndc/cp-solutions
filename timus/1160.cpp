#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
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
    int N, M; cin >> N >> M;
    vector<array<int, 3>> edges(M);
    for (int i = 0; i < M; i++) {
        int x, y , w; cin >> x >> y >> w;
        --x,--y;
        edges.push_back({w, x, y});
    }
    sort(edges.begin(), edges.end());
    UnionFind dsu(N);
    vector<pii> ans;
    int mxw = 0;
    for (auto &[w, u, v]: edges) {
        if (dsu.unite(u, v)) {
            mxw = max(mxw, w);
            ans.push_back({u, v});
        }
    }
    cout << mxw << '\n';
    cout << ans.size() << '\n';
    for (auto [x, y]: ans) cout << x + 1 << ' ' << y + 1<< '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}