#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
struct UnionFind {
    vector<int> par, sz, miny;
    // O(n)
    // representante é o menor y do compoennte
    UnionFind(int n, const vector<int>& y) {
        par.assign(n, 0);
        sz.assign(n, 1);
        miny.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++) {
            miny[i] = y[i];
        }
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
        miny[x_root] = min(miny[x_root], miny[y_root]);
        return true;  // (some condition met for component);
    }
};
void solve() {
    int N; cin >> N;
    vector<int> x(N), y(N), p(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int v1, int v2){
        return x[v1] < x[v2];
    });
    UnionFind dsu(N, y);
    auto cmp = [&](int a, int b){ return dsu.miny[a] < dsu.miny[b];};
    // menor y
    set<int,decltype(cmp)> s(cmp);
    for (int i = 0; i < N; i++) {
        int cur = p[i];
        // pega todo mundo q tem y menor q o cara atual e mergeia
        while(!s.empty() && dsu.miny[*s.begin()] < y[cur]) {
            dsu.unite(cur, *s.begin());
            s.erase(s.begin());
        }
        // insere a root pra representar o componente
        s.insert(dsu.find(cur));
    }
    for (int i = 0; i < N; i++) {
        cout << dsu.sz[dsu.find(i)] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}