#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int maxn = 1e9;
vector<int> is_removed, sz;
vector<vector<int>> tree;

int get_subtree_sz(int u, int p = -1) {
    sz[u] = 1;
    for (int v : tree[u]) {
        if (v == p || is_removed[v]) continue;
        sz[u] += get_subtree_sz(v, u);
    }
    return sz[u];
};

int get_centroid(int u, int size, int p = -1) {
    for (int v : tree[u]) {
        if (v == p || is_removed[v]) continue;
        if (sz[v] * 2 > size) {
            return get_centroid(v, size, u);
        }
    }
    return u;
}

vector<pair<int, int>> ans;
vector<int> seen1, seen2;
void build_decomp(int u) {
    int sub_size = get_subtree_sz(u);
    int centroid = get_centroid(u, sub_size);
    ans.push_back({1, centroid + 1});
    if (sub_size > 2) {
        ans.push_back({2, centroid + 1});
    }
    is_removed[centroid] = true;
    for (int v : tree[centroid]) {
        if (is_removed[v]) continue;
        build_decomp(v);
    }
}

void solve() {
    int n;
    cin >> n;
    tree.assign(n, vector<int>());
    is_removed.assign(n, false);
    seen1.assign(n, false);
    seen2.assign(n, false);
    sz.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    build_decomp(0);
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
    ans.clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}