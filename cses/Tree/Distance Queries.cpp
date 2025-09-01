#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

template<typename T> class SparseTable {
    private:
        int n, k;
        vector<vector<T>> st;
    public: 
    SparseTable(const vector<T> & v) {
        n = v.size(); k = 31 - __builtin_clz(n) + 1;
        st.resize(k); st[0] = v;
        for (int i = 1; i < k; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) 
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return min(st[p][l], st[p][r - (1 << p) + 1]);
    }
};

template<typename T>
class LCA {
    private:
        int n; const vector<vector<T>> &g;
        SparseTable<pair<T, T>> rmq;
        vector<T> tin, et, depth;
        int timer = 0;

        // O(n)
        void dfs(int u = 0, int p = -1) {
            tin[u] = timer;
            et[timer++] = u;
            for (int v: g[u]) {
                if (v != p) {
                    depth[v] = depth[u] + 1;
                    dfs(v, u);
                    et[timer++] = u;
                }
            }
        }

    public: 
        // Build O(nlogn)
        LCA(vector<vector<T>> & _g): n(_g.size()), g(_g), tin(n), et(2 * n), depth(n), rmq(vector<pair<T ,T>>(1)) {
            dfs();
            vector<pair<T, T>> arr(2 * n);
            for (int i = 0; i <  2 * n; i++) {arr[i] = {depth[et[i]], et[i]}; };
            rmq = SparseTable<pair<T, T>>(arr);
        }

        // O(1)
        T query(int a, int b) {
            if (tin[a] > tin[b]) swap(a, b);
            return rmq.query(tin[a], tin[b]).second;
        }

        // O(1)
        T dist(int a, int b) {
            return depth[a] + depth[b] - 2 * depth[query(a, b)];
        }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> g(maxn);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    LCA<int> lca(g);
    for(; q > 0; q--) {
        int a, b; cin >> a>> b; a--, b--;
        cout << lca.dist(a, b) << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}