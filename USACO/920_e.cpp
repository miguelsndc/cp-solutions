#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

int n, m, cnt = 0, sz = 0; 
vector<int> vis(maxn);
set<int> s[maxn];
void dfs(int u) {
    sz++;
    vis[u] = true;
    for (int i = 0; i < n; i++) {
        if (!s[u].count(i)) {
            if (!vis[i]) dfs(i);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        s[u].insert(v);
        s[v].insert(u);
    }

    vector<int> comps;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            sz = 0;
            cnt++; dfs(i);
            comps.push_back(sz);
        }
    }
    sort(begin(comps), end(comps));
    cout << cnt << '\n';
    for (int x: comps) {
        cout << x << ' ';
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
