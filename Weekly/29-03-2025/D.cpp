#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;
    array<int, maxn> r, g;
    vector<pair<int, int>> adj[maxn];
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> g[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<i64> dist(maxn, inf);
    dist[0] = 0;

    min_heap<pair<i64, i64>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] != cost)
            continue;

        int cycle = r[u] + g[u];  // tempo do ciclo
        int p = cost % cycle;     // aonde a gente ta no ciclo r -> g -> r ..
        // se p < red entao a gnt ta no sinal vermelho e pode andar
        // se nao a gente tem q esperar ate o ciclo reiniciar e isso custa cycle - p
        // (volta pro zero)
        int t_leave = (p < r[u]) ? cost : cost + (cycle - p);

        for (auto [v, w] : adj[u]) {
            if (dist[v] > w + t_leave) {
                dist[v] = w + t_leave;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[n - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}