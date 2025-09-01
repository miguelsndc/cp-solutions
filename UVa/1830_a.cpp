#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector
#define pb push_back

void solve() {
    int n;
    cin >> n;
    int u, v;
    vc<vc<pair<int, int>>> t(n + 1);
    vc<int> id(n + 1), dp(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        t[u].pb({v, i});
        t[v].pb({u, i});
    }
    id[1] = 0;
    dp[1] = 1;
    auto dfs = [&](auto&& f, int u, int p) -> void {
        for (auto [v, i] : t[u]) {
            if (dp[v] == 0) {
                dp[v] = dp[u] + (i <= id[u]);
                id[v] = i;
                f(f, v, u);
            }
        }
    };
    dfs(dfs, 1, 0);
    cout << *max_element(all(dp)) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}