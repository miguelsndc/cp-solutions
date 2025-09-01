#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define int long long

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e18 + 1;

void solve() {
    int k, n, m; cin >> k >> n >> m;
    vector<vector<array<int, 3>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, t, h; cin >> a >> b >> t >> h;
        g[--a].push_back({--b, t, h});
        g[b].push_back({a, t, h});
    }
    int src, dest; cin >> src >> dest; --src, --dest;
    min_heap<array<int, 3>> pq;
    vector dist(n, vector<int>(k, inf));
    pq.push({0, 0, src});
    dist[src][0] = 0;
    while(!pq.empty()) {
        auto [cost, dmg, u] = pq.top(); pq.pop();
        if (dist[u][dmg] != cost) continue;
        for (auto [v, t, h]: g[u]) {
            int new_dmg = dmg + h;
            if (new_dmg < k and dist[v][new_dmg] > (dist[u][dmg] + t)) {
                dist[v][new_dmg] = (dist[u][dmg] + t);
                pq.push({dist[v][new_dmg], new_dmg, v});
            }
        }
    }
    int ans = *min_element(all(dist[dest]));
    cout << (ans == inf ? -1 : ans);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}