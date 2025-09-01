#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    vc<vc<ii>> g;
    g.assign(n, vc<ii>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vc<bool> visited(n, 0);
    auto dfs = [&](auto&& self, int u, int cost) -> int {
        int mx = 0;
        visited[u] = true;
        for (auto [v, w] : g[u]) {
            if (!visited[v]) {
                mx = max(mx, self(self, v, cost + w));
            }
        }
        return max(cost, mx);
    };

    cout << dfs(dfs, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}