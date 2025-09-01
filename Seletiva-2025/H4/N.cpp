#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

vector<ll> min_cost(int n, int origin, vector<pair<int ,int>> *flights) {
    vector<ll> dist(n, INT64_MAX);
    vector<bool> visited(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, origin});
    dist[origin] = 0;
    while(!pq.empty()) {
        auto [d, node] = pq.top();pq.pop();
        visited[node] = true;
        if (dist[node] < d) continue;
        for (const auto &[to, weight]: flights[node]) {
            if (visited[to]) continue;
            ll cost = dist[node] + weight;
            if (cost < dist[to]) {
                dist[to] = cost;
                pq.push({cost, to});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> forward[n];
    vector<pair<int, int>> backward[n];
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        forward[a].push_back({b, c});
        backward[b].push_back({a, c});
    }

    vector<ll> going = min_cost(n, 0, forward);
    vector<ll> coming = min_cost(n, n - 1, backward);

    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++) {
        for (const auto &[to, cost]: forward[i]) {
            if (going[i] == INT64_MAX || coming[to] == INT64_MAX) {
                continue;
            }
            ans = min(ans, going[i] + (cost / 2) + coming[to]); 
        }
    }
    cout << ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
         solve();
    }
}