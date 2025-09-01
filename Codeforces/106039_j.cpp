#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

void solve() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    --S, --T;

    vector<vector<int>> g(N);
    vector<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back(minmax(u,v));
    }

    auto dale = [&](int src) -> pair<vector<ll>, vector<ll>> {
        vector<ll> dp(N), dist(N, 1e9), vis(N, false);
        dp[src] = 1;
        dist[src] = 0;
        vis[src] = true;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                // achei caminho
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    dp[v] = dp[u];
                    vis[v] = true;
                    q.push(v);
                // existe outro melhor caminho ate aqui
                } else if (dist[v] == dist[u] + 1) {
                    dp[v] = (dp[v] + dp[u]) % mod;
                }
            }
        }
        return {dp, dist};
    };

    auto [dp_s, dist_s] = dale(S);
    auto [dp_t, dist_t] = dale(T);

    auto printa = [&](vector<ll> &v) {
        for (auto x: v) cout << x << ' ';
        cout << '\n';
    };

    // printa(dp_s);
    // printa(dist_s);
    // cout << "\n\n";
    // printa(dp_t);
    // printa(dist_t);
    // cout << "\n\n";

    int D = dist_s[T]; // S -> T
    ll ans = 0;

    for (auto [u, v] : edges) {
        // if (u == T or v == S) continue;
        // S -> U + (u,v) + V -> T == (D + 1)
        // printf("To indo de %d pra %d com distancia %d e %d\n", u, v, dist_s[u], dist_t[v]);
        if (dist_s[u] + 1 + dist_t[v] == D + 1)
            ans = (ans + dp_s[u] * dp_t[v] % mod) % mod;
        // S -> V + (u,v) + U -> T == (D + 1)
        if (dist_s[v] + 1 + dist_t[u] == D + 1)
            ans = (ans + dp_s[v] * dp_t[u] % mod) % mod;
    }

    cout << ans * 500000004LL % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) solve();
}
