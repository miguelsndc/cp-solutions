#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    Disjoint Set Union with path compression
    Complexidade:
        - find(u) O(alpha(n))
        - unite(u) O(alpha(n))
*/
struct UnionFind {
    int maxsize = 1;
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
        maxsize = max(maxsize, sz[x_root]);
        return true;  // (some condition met for component);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, q; cin >> n >> k >> q;
    vector<bool> cleared(n);
    // pra cada trait (a string), dado os caracteres q ela tem
    // da merge em todo mundo com aqueles caracteres
    vector traits(k, vector<vector<int>>(11));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < k; j++) {
            traits[j][int(s[j]-'a')].push_back(i);
        }
    }
    UnionFind uf(n);
    while(q--) {
        int t; cin >> t;
        if (t==1) {
            int tr; cin >> tr; --tr;
            for (int c = 0; c < 10; c++) {
                for (int i = 1; i < traits[tr][c].size(); i++) {
                    uf.unite(traits[tr][c][i], traits[tr][c][i - 1]);
                }
                traits[tr][c].clear();
            }
        }
        if (t==2) {
            int x; cin >> x; --x;
            cout << uf.sz[uf.find(x)] << '\n';
        } 
        if (t==3) {
            cout << uf.maxsize << '\n';
        }
    }
}