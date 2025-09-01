#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define ld long double
#define pii pair<int, int>

const ll INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;
const ld EPS = 1e-9;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<array<int, 3>> g[1005];
int n, m;

int dijkstra(int f) {
    vector<int> d(1005, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;

    d[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if (d[node] != cost) continue;
        for (const auto&[to, weight, flow]: g[node]) {
            if (flow >= f && d[node] + weight < d[to]) {
                d[to] = d[node] + weight;
                pq.push({d[to], to});
            }
        }
    }

    if (d[n] != INT32_MAX) {
        return (f * 1.0 / d[n]) * 1000000; 
    }      

    return -1;
}

void solve() {
    cin >> n >> m;
    vector<int> flows(m);
    for (int i = 0; i < m; i++) {
        int u, v, c, f; cin >> u >> v >> c >> f;
        g[u].push_back({v, c, f});
        g[v].push_back({u, c, f});
        flows[i] = f;
    }

    int max_ratio = -1;
    for (int flow: flows) {
        max_ratio = max(max_ratio, dijkstra(flow));
    }
    cout << max_ratio;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("pump");
    #endif
    int tt = 1; // cin >> tt;
    for(int t = 1; t <= tt; t++) {
         // cout << "Case #" << t << ": ";
         solve();
    }
}