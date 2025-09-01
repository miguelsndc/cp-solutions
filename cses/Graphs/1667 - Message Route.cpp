#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi previous(n + 1, -1);
    queue<int> q;
    q.push(1);
    previous[1] = -2;
    int v;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (v == n) {
            break;
        }
        for (auto u : adj[v]) {
            if (previous[u] != -1) continue;
            q.push(u);
            previous[u] = v;
        }
    }

    if (v != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vi path;
    path.push_back(v);
    while (previous[v] != -2) {
        v = previous[v];
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto r : path) {
        cout << r << ' ';
    }

    return 0;
}