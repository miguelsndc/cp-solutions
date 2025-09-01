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

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int dfs(int i, int at, vector<vi> &adj, vb &visited, vi &ordering) {
    visited[at] = true;
    for (auto u : adj[at]) {
        if (!visited[u]) {
            i = dfs(i, u, adj, visited, ordering);
        }
    }
    ordering[i] = at;
    return i - 1;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     setIO("1680");
    // #endif

    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[--a].push_back(--b);
    }

    vi ordering(n, -1);
    vb visited(n);
    dfs(n - 1, 0, adj, visited, ordering);

    vi dist(n, INT_MIN);
    vi prev(n, -1);
    dist[0] = 0;
    prev[0] = -2;
    for (auto node : ordering) {
        if (node == -1) continue;
        for (auto e : adj[node]) {
            if (dist[node] + 1 > dist[e]) {
                dist[e] = dist[node] + 1;
                prev[e] = node;
            }
        }
    }

    if (ordering[n - 1] == -1 || dist[n - 1] == INT_MIN) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vi path;
    for (int at = n - 1; at != -2; at = prev[at]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto c : path) {
        cout << c + 1 spe;
    }

    return 0;
}