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
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    vector<vector<pll>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[--a].push_back({--b, c});
    }

    priority_queue<ll> routes[n];
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    routes[0].push(0);
    while (!pq.empty()) {
        ll min_v = pq.top().f, index = pq.top().s;
        pq.pop();
        if (routes[index].top() < min_v) {
            continue;
        }
        for (auto edge : g[index]) {
            ll to = edge.f, cost = edge.s;
            ll temp_dist = min_v + cost;

            if (routes[to].size() < k) {
                routes[to].push(temp_dist);
                pq.push({temp_dist, to});
            } else if (temp_dist < routes[to].top()) {
                routes[to].pop();
                routes[to].push(temp_dist);
                pq.push({temp_dist, to});
            }
        }
    }

    vector<ll> answer;
    while (!routes[n - 1].empty()) {
        answer.push_back(routes[n - 1].top());
        routes[n - 1].pop();
    }

    reverse(answer.begin(), answer.end());

    for (auto d : answer) {
        cout << d spe;
    }

    return 0;
}