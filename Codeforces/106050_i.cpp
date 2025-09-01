#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int inf = 1e9 + 9;
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}
void solve() {
    int N, M, P;
    cin >> N >> M >> P;
    vector g(N + 1, vector<pii>());
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> f(P + 1), t(P + 1);
    for (int i = 1; i <= P; i++) cin >> f[i];
    for (int i = 1; i <= P; i++) cin >> t[i];

    auto dijsktra = [&](int src) -> vector<int> {
        vector<int> dist(N + 1, inf);
        dist[src] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[src], src});
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (dist[u] != cost) continue;
            for (auto [v, w] : g[u]) {
                if (chmin(dist[v], dist[u] + w)) {
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };

    vector dist(P + 1, vector<int>(P + 1, inf));
    vector<int> hotel = dijsktra(N);
    for (int i = 1; i <= P; i++) {
        vector<int> d = dijsktra(i);
        for (int j = 1; j <= P; j++) {
            dist[i][j] = d[j];
        }
        dist[0][i] = hotel[i];
    }

    vector dp((1 << P), vector<int>(P, inf));
    for (int i = 0; i < P; i++) {
        dp[(1 << i)][i] = dist[0][i + 1] + t[i + 1];
    }

    // dp[mask][last] melhor custo se visitei mask cidades e a ultima foi last
    for (int mask = 1; mask < (1 << P); mask++) {
        for (int last = 0; last < P; last++) {
            if (!(mask & (1 << last))) continue;
            for (int next = 0; next < P; next++) {
                if ((mask & (1 << next))) continue;
                int new_mask = mask | (1 << next);
                chmin(dp[new_mask][next], dp[mask][last] + dist[last + 1][next + 1] + t[next + 1]);
            }
        }
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << P); mask++) {
        for (int last = 0; last < P; last++) {
            // consigo chegar aqui
            if (dp[mask][last] <= 960) {
                int cur = 0;
                for (int i = 0; i < P; i++) {
                    if (mask & (1 << i)) cur += f[i + 1];
                }
                chmax(ans, cur);
            }
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}