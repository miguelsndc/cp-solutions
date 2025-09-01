#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 300;

bool usable[MAXN][MAXN];
vector<int> dist(MAXN);
vector<ii> g[MAXN];

int dijkstra(int src, int dest) {
    for (int i = 0; i < 300; i++) dist[i] = INT32_MAX;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        auto [cost, from] = pq.top();
        pq.pop();
        if (dist[from] != cost) continue;
        if (from == dest) return cost;
        for (const auto &[to, weight]: g[from]) {
            if (!usable[from][to]) continue;
            if (dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
                pq.push({dist[to], to});
            }
        }
    }

    return -1;
}

void solve() {
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++) {
            usable[i][j] = true;
        }
    }

    int n, m, q; cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    while(q--) {
        int q, u, v; cin >> q >> u >> v;
        if (q) {
            int d = dijkstra(u, v);
            if (d == -1) {
                cout << "IMPOSSIBLE\n";
            } else {
                cout << d << '\n';
            }
        } else {
            usable[u][v] = usable[v][u] = false;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}