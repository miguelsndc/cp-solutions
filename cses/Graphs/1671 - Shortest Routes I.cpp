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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, from, to;
    ll cost;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    vb visited(n + 1, false);
    vll dist(n + 1, LONG_LONG_MAX);
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll min_value = pq.top().f;
        ll index = pq.top().s;
        pq.pop();
        visited[index] = true;
        if (dist[index] < min_value) continue;
        for (auto edge : graph[index]) {
            if (visited[edge.f]) {
                continue;
            }
            ll new_dist = dist[index] + edge.s;
            if (new_dist < dist[edge.f]) {
                dist[edge.f] = new_dist;
                pq.push({new_dist, edge.f});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] spe;
    }

    return 0;
}