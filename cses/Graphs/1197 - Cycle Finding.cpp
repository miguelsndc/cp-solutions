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
int main() {
    typedef tuple<int, int, ll> Edge;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<Edge> edges;
    int n, m, a, b;
    ll w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    for (int i = 1; i <= n; i++) {  // fictional start node
        edges.push_back({0, i, 0});
    }

    vll distance(n + 1, INF);
    vi prev(n + 1, -1);
    distance[0] = 0;
    distance[1] = 0;
    int x;
    for (int u = 0; u < n; u++) {
        x = -1;
        for (auto edge : edges) {
            int from, to;
            ll cost;
            tie(from, to, cost) = edge;
            if (distance[from] != INF && distance[from] + cost < distance[to]) {
                distance[to] = distance[from] + cost;
                prev[to] = from;
                x = to;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (prev[x] == 0) {
            break;
        }
        x = prev[x];
    }

    vi cycle;
    for (int v = x;; v = prev[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1) {  // once we hit a back edge and have something in the cycle we stop
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int p : cycle) {
        cout << p spe;
    }

    return 0;
}
