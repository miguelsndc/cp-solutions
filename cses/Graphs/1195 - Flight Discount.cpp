#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

vll min_costs(int start, const vector<vector<pll>> &g) {
    int n = g.size() + 1;
    vb visited(n);
    vll distance(n, INT64_MAX);
    distance[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        ll min_value = pq.top().f, index = pq.top().s;
        pq.pop();
        for (auto edge : g[index]) {
            ll to = edge.f, cost = edge.s;
            if (visited[to]) continue;
            ll new_distance = distance[index] + cost;
            if (new_distance < distance[to]) {
                distance[to] = new_distance;
                pq.push({new_distance, to});
            }
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll a, b, c;
    cin >> n >> m;
    vector<vector<pll>> forwards(n + 1);
    vector<vector<pll>> backwards(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        forwards[a].push_back({b, c});
        backwards[b].push_back({a, c});
    }

    vll start_costs = min_costs(1, forwards);
    vll end_costs = min_costs(n, backwards);
    ll min_total = INT64_MAX;
    for (int u = 1; u <= n; u++) {
        for (auto &[p, pc] : forwards[u]) {
            if (start_costs[u] == INT64_MAX || end_costs[p] == INT64_MAX) {
                continue;
            }
            min_total = min(min_total, start_costs[u] + (pc / 2) + end_costs[p]);
        }
    }
    cout << min_total;

    return 0;
}