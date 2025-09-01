#include <vector>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5e4 + 1;
vector<int> g[MAXN];
int color[MAXN], ans[MAXN], heavy[MAXN], sz[MAXN];

void find_subtree_sizes(int u, int parent = -1) {
    sz[u] = 1;
    for (int child : g[u]) {
        if (child != parent) {
            find_subtree_sizes(child, u);
            sz[u] += sz[child];
        }
    }
}

void find_heavy_child(int u, int parent = -1) {
    int max_size = -1, heavy_child = -1;
    for (int child : g[u]) {
        if (child != parent) {
            if (sz[child] > max_size) {
                heavy_child = child, max_size = sz[child];
            }
        }
    }
    heavy[u] = heavy_child;
}

void dfs(int u, int parent, set<int>& s) {
    if (heavy[u] != -1) {
        dfs(heavy[u], u, s);  
    }

    for (int child : g[u]) {
        if (child != parent && child != heavy[u]) {
            set<int> child_set;
            dfs(child, u, child_set);  
            
            if (child_set.size() > s.size()) {
                swap(child_set, s);
            }
            for (int c : child_set) {
                s.insert(c);
            }
        }
    }

    if (color[u] != 0) {
        s.insert(color[u]);
    }

    ans[u] = s.size();
}

void solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        color[i] = ans[i] = 0;
        heavy[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        int u, c; cin >> u >> c;
        color[u] = c;  
    }

    find_subtree_sizes(1);
    find_heavy_child(1);

    set<int> s;
    dfs(1, -1, s);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        solve(n, m);
    }
}