#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

int n; string h; int subtree_cnt[(maxn << 1)]; bool subtree_dest[(maxn << 1)];
vector<int> g[(maxn << 1)];

int precompute1(int u = 0, int p = -1) {
    subtree_cnt[u] = 0;
    for (int v : g[u]) {
        if (v != p) {
            subtree_cnt[v] += precompute1(v, u);
            subtree_cnt[u] += subtree_cnt[v];
        }
    }
    return (h[u] == '1');
}

int precompute2(int u = 0, int p = -1) {
    subtree_dest[u] = false;
    for (int v: g[u]) {
        if (v != p) {
            subtree_dest[v] |= precompute2(v, u);
            subtree_dest[u] |= subtree_dest[v];
        }
    }
    return (u == (n - 1));
}

int dfs(int u = 0, int p = -1, int cost = 0) {
    int dest_subtree = -1;
    for (int v: g[u]) {
        if (subtree_dest[v] and v != p) {
            dest_subtree = v;
            break;
        }
    }
    for (int v: g[u]) {
        if (subtree_cnt[v] > 0 && v != dest_subtree and v != p) {
            cost = dfs(v, u, cost + 2);
        }
    }
    if (dest_subtree != -1) {
        cost = dfs(dest_subtree, u, cost + 1);
    }
    return cost;
}

void solve() {
    cin >> n >> h;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    precompute1();
    precompute2();
    int cost = dfs();
    cout << cost << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}