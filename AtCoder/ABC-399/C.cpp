#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

vector<int> g[maxn], visited(maxn, false);

int cnt = 0;
void dfs(int u, int p = -1) {
    cnt++;
    visited[u] = true;
    for (int v: g[u]) {
        if (!visited[v]) dfs(v, u);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    int total_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // for a connected component with size k, we must have k - 1 edges
            // reduce (no edges) - (k - 1)
            // either way gotta calculate number of edges
            cnt = 0; dfs(i);
            total_cnt += cnt - 1;
        }
    }
    cout << m - total_cnt;
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