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

const ll inf = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<ii> adj[n];
    vector<ll> s(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<ll>> dist(1001, vector<ll>(1001, inf));
    vector<vector<bool>> visited(1001, vector<bool>(1001));
    min_heap<array<ll, 3>> pq;

    pq.push({0, 0, s[0]});
    dist[0][s[0]] = 0;

    while(!pq.empty()) {
        auto [cost, u, b] = pq.top();
        pq.pop();
        if (visited[u][b] || dist[u][b] == inf) continue;
        visited[u][b] = true;
        for (const auto&[to, weight]: adj[u]) {
            ll c = min(b, s[to]);
            if (dist[to][c] > dist[u][b] + 1LL * weight * b) {
                dist[to][c] = dist[u][b] + 1LL * weight * b;
                pq.push({dist[to][c], to, c});
            }
        }
    }
    ll ans = inf;
    for (int i = 1; i <= 1000; i++) {
        ans = min(ans, dist[n - 1][i]);
    }
    cout << ans << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
         solve();
    }
}