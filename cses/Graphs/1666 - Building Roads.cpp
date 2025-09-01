#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void dfs(int c, vector<vi> &adj, vector<bool> &visited) {
    if (visited[c]) return;
    visited[c] = true;
    for (auto u : adj[c]) {
        dfs(u, adj, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<bool> visited(n + 1);
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi disconnected;
    dfs(1, adj, visited);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            disconnected.push_back(i);
            dfs(i, adj, visited);
        }
    }

    cout << disconnected.size() << '\n';
    for (int disc : disconnected) {
        cout << 1 << ' ' << disc << '\n';
    }

    return 0;
}