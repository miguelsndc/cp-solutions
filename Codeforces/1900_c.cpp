#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int n;
    cin >> n;
    string let;
    cin >> let;
    vector<vector<pair<int, char>>> g(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (l != -1) {
            g[i].push_back({l, 'L'});
            g[l].push_back({i, 'L'});
        }
        if (r != -1) {
            g[i].push_back({r, 'R'});
            g[r].push_back({i, 'R'});
        }
    }
    vector<int> leaf(n);

    int ans = 1e9 +1;
    auto dfs = [&](auto &&self, int u, int p = -1, int score) -> void {
        if (g[u].size() == 1 and g[u][0].F == p) {
            ans = min(ans, score);
            return;
        }

        for (auto [v, c]: g[u]) {
            if (v != p) {
                self(self, v, u, score + (c != let[u]));
            }
        }
    };
    dfs(dfs, 0, -1, 0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;   cin >> T;
    while (T--) solve();
}