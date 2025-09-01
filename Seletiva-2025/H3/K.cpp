#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

vector<int> path;

bool cycle = false;

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
        cout << node + 1 << ' ';
    }
}

void dfs(int i, int prev, vector<int> *g, vector<int> & visited) {
    if (cycle) return;

    if (visited[i]) {
        if (path.size() > 2) {
            answer(i, path);
        }
        return;
    }

    path.push_back(i);
    visited[i] = true;
    for (int neighbour: g[i]) {
        if (neighbour != prev) {
            dfs(neighbour, i, g, visited);
        }
    }

    path.pop_back();
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, -1, g, visited);
        }
    }

    if (!cycle) {
        cout << "IMPOSSIBLE";
    }
}