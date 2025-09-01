#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

void solve() {
    ll n, m, x;
    cin >> n >> m >> x;

    vc<pair<int, int>> g[maxn];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back({--v, 0});
        g[v].push_back({u, 1});
    }
    priority_queue<array<ll, 3>, vc<array<ll, 3>>, greater<array<ll, 3>>> pq;
    vc<vc<ll>> dist(n, vc<ll>(2, numeric_limits<ll>::max()));
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto [cost, node, modo] = pq.top();
        pq.pop();
        if (dist[node][modo] != cost) continue;
        for (auto [v, type] : g[node]) {
            if (type == modo and dist[v][modo] > dist[node][modo] + 1) {
                dist[v][modo] = dist[node][modo] + 1;
                pq.push({dist[v][modo], v, modo});
            }
        }
        if (dist[node][modo ^ 1] > dist[node][modo] + x) {
            dist[node][modo ^ 1] = dist[node][modo] + x;
            pq.push({dist[node][modo ^ 1], node, modo ^ 1});
        }
    }
    cout << min(dist[n - 1][0], dist[n - 1][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}