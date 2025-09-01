#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

void dfs(int i, vector<int> *g, vector<bool> &visited) {
    visited[i] = true;
    for (auto neighbour: g[i]) {
        if (!visited[neighbour]) {
            dfs(neighbour, g, visited);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> g[n];
    vector<int> g_transp[n];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g_transp[b].push_back(a);
    }

    vector<bool> visited(n);
    dfs(0, g, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << 1 << ' ' <<  i + 1;
            return 0;
        }
    }

    fill(begin(visited), end(visited), false);
    dfs(0, g_transp, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i + 1 << ' ' <<  1;
            return 0;
        }
    }

    cout << "YES";
}