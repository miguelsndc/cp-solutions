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

#define INF 1e18
#define MINUS_INF -1e18

// negate all weights
// do bellman ford
// if negative cycle happened print out -1
int main() {
    typedef tuple<ll, ll, ll> Edge;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, x;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> x;
        edges.push_back({a, b, -x});
    }

    // handle the edge case
    if (n == 1) {
        int cost;
        tie(ignore, ignore, cost) = edges[m - 1];
        if (cost < 0) {
            cout << -1;
            return 0;
        }
    }

    vll distance(n + 1, INF);
    distance[1] = 0;

    int relaxed = true;
    for (int i = 0; i < n - 1 && relaxed; i++) {
        relaxed = false;
        for (auto edge : edges) {
            int from, to, cost;
            tie(from, to, cost) = edge;
            if (distance[from] != INF && distance[from] + cost < distance[to]) {
                distance[to] = distance[from] + cost;
                relaxed = true;
            }
        }
    }

    relaxed = true;
    for (int i = 0; i < n - 1 && relaxed; i++) {
        relaxed = false;
        for (auto edge : edges) {
            int from, to, cost;
            tie(from, to, cost) = edge;
            if (distance[from] != INF && distance[from] + cost < distance[to]) {
                distance[to] = MINUS_INF;
                relaxed = true;
            }
        }
    }

    if (distance[n] == MINUS_INF) {
        cout << -1;
        return 0;
    }

    cout << -distance[n];

    return 0;
}