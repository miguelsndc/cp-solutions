#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5, log2dist = 31;

vector<vector<int>> up;
vector<int> tree[maxn], parent, depth;

void preprocess(int n) {
    for (int v = 0; v < n; v++)
        up[v][0] = parent[v];
    for (int i = 1; i < log2dist; i++) {
        for (int v = 0; v < n; v++) {
            if (v != 0) depth[v] = depth[parent[v]] + 1;
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
    }
}

void dfs(int u, int p = 0) {
    for (int v : tree[u]) {
        if (v != p) {
            dfs(v, u);
            parent[v] = u;
        }
    }
}

int kth_ancestor(int node, int k) {
    if (depth[node] < k) return -1;
    for (int i = 0; i < log2dist; i++) {
        if (k & (1 << i)) {
            node = up[node][i];
        }
    }
    return node + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }

    parent.assign(n, 0);
    depth.assign(n, 0);
    up.assign(n, vector<int>(log2dist, 0));

    parent[0] = 0;
    dfs(0);
    preprocess(n);
    while (q--) {
        int node, k;
        cin >> node >> k;
        cout << kth_ancestor(--node, k) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}