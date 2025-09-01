#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 3e5 + 5;
vector<int> sz(mxn);
vector<vector<int>> g(mxn);
int dfs(int u, int p) {
    sz[u] = 1;
    for (int v: g[u]) {
        if (v == p) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << sz[i] - 1<< ' ';
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
