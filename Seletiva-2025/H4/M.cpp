#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5 + 5;

void solve() {
    int n, m, t0, t1, t2; 
    cin >> n >> m;
    vector<array<int, 3>> g[maxn];
    cin >> t0 >> t1 >> t2;
    for (int i = 0; i < m; i++) {
        int u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        g[u].push_back({v, l1, l2});
        g[v].push_back({u, l1, l2});
    }

    priority_queue<ii> pq;
    vector<int> dist(n + 1, -1e9);
    dist[n] = t0;
    pq.push({dist[n], n});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int cost = p.fi, u = p.se;
        if (u == 1) break; 
        for (auto e : g[u]) {
            auto [v, l1, l2] = e;
            int d1 = (cost - l1 >= t2 || cost <= t1) ? cost - l1 : cost - l2;
            if (d1 == cost - l2) d1 = max(d1, t1 - l1);
            if (dist[v] < d1) {
                dist[v] = d1;
                pq.push({d1, v});
            }
        }
    }

    cout << (dist[1] >= 0 ? dist[1] : -1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; 
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        solve();
    }
}