#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MOD 1000000007

int cycle = false;

void answer(int node, vector<int> &path) {
    cycle = true;
    vector<int> actual_cycle = {node};
    for (int i = path.size() - 1; i >= 0; i--) {
        actual_cycle.push_back(path[i]);
        if (path[i] == node) {  
            break;
        }
    }
    cout << actual_cycle.size() << '\n';
    for (int node : actual_cycle) {
        cout << node << ' ';
    }
}

void dfs(int node, int parent, vector<vector<int>> &g, vector<int> &visited, vector<int> &path) {
    if (cycle) return;

    if (visited[node]) {        
        if (path.size() > 2) {  
            answer(node, path);
        }
        return;
    }
    visited[node] = true;
    path.push_back(node);
    for (int child : g[node]) {
        if (child != parent) {
            dfs(child, node, g, visited, path);
        }
    }
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> visited(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> path;
            dfs(i, -1, g, visited, path);
        }
    }
    if (!cycle) {
        cout << "IMPOSSIBLE" << '\n';
    }
}