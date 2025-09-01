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

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int n, m;
const ll inf = LONG_LONG_MAX;
vector<ii> adj[100005];

ll dijkstra(int offset) {
    vector<vector<ll>> dist(100005, vector<ll>(3, inf));
    min_heap<array<ll, 3>> pq;

    // (cost, node, remainder 3)
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()) {
        auto [c, from, mod] = pq.top();
        pq.pop();
                                                            // acaba qnd chega em n - 1
        if (c > dist[from][mod] || from == n - 1) continue;
        for (const auto &[to, cost]: adj[from]) {
            int new_mod = (mod + 1) % 3;
            if (dist[to][new_mod] > dist[from][mod] + cost) {
                dist[to][new_mod] = dist[from][mod] + cost;
                pq.push({dist[to][new_mod], to, new_mod});
            }
        }
    }

    ll ans = inf;
    for (int i = 0; i < 3; i++) {
        if ((i - offset + 3) % 3 == 0) {
            ans = min(ans, dist[n-1][i]);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<pair<ll, string>> results = {
        {dijkstra(0), "me"},
        {dijkstra(1), "Gon"},
        {dijkstra(2), "Killua"},
    };

    sort(begin(results), end(results));

    for (const auto &[d, s]: results) {
        cout << s << '\n';
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
