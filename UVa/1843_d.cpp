#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> t(n + 1);
    vector<ll> cnt(n + 1);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    auto dfs = [&](auto&& self, int u, int p) {
        if (t[u].size() == 1 and t[u][0] == p) {
            return cnt[u] = 1;
        }

        for (int v : t[u]) {
            if (v != p) {
                cnt[u] += self(self, v, u);
            }
        }

        return cnt[u];
    };

    dfs(dfs, 1, 0);

    int q, x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        cout << cnt[x] * cnt[y] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}