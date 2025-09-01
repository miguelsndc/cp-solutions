#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;
constexpr int maxlg = 31 - __builtin_clz(maxn) + 1;

template<typename T> class SparseTable {
    private:
        int n, log2dist;
        vector<vector<T>> st;
    public: 
    SparseTable(const vector<T> & value) {
        n = value.size();
        log2dist = 31 - __builtin_clz(n) + 1;
        st.resize(log2dist);
        st[0] = value;
        for (int p = 1; p < log2dist; p++) {
            st[p].resize(n - (1 << p) + 1);
            for (int i = 0; i + (1 << p) <= n; i++) {
                st[p][i] = min(st[p - 1][i], st[p - 1][i + (1 << (p - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return min(st[p][l], st[p][r - (1 << p) + 1]);
    }
};

class LCA {
    private:
        int n; const vector<vector<int>> &g;
        SparseTable<pair<int, int>> rmq;
        vector<int> tin, et, depth;
        int timer = 0;

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
        LCA(vector<vector<int>> & _g): n(_g.size()), g(_g), tin(n), et(2 * n), depth(n), rmq(vector<pair<int ,int>>(1)) {
            dfs();
            vector<pair<int, int>> arr(2 * n);
            for (int i = 0; i <  2 * n; i++) {arr[i] = {depth[et[i]], et[i]}; };
            rmq = SparseTable<pair<int, int>>(arr);
        }

        int query(int a, int b) {
            if (tin[a] > tin[b]) swap(a, b);
            return rmq.query(tin[a], tin[b]).second;
        }

        int dist(int a, int b) {
            return depth[a] + depth[b] - 2 * depth[query(a, b)];
        }
};


void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> g(maxn);
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    LCA lca(g);
    for(; q > 0; q--) {
        int a, b; cin >> a >> b; a--, b--;
        cout << lca.query(a, b) + 1 << '\n';
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