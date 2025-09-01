#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009
#define pii pair<ll, ll>

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<pii> g[n];
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        g[a].push_back({c, b});
    }
    // (weight, to);
    vector<ll> dist(n, LONG_LONG_MAX), processed(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()) {
        auto [cost, from] = pq.top();
        pq.pop();
        if(processed[from]) continue;
        processed[from] = true;
        for (const auto&[adj_cost, adj_to]: g[from]) {
            if (dist[from] + adj_cost < dist[adj_to]) {
                dist[adj_to] = dist[from] + adj_cost;
                pq.push({ dist[adj_to], adj_to });
            }
        }
    }

    for (ll d: dist) {
        cout << d << ' ';
    }
}