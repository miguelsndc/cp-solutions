#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

void dfs(int i, vector<int> *g, vector<bool> &visited) {
    visited[i] = true;
    for (int adj: g[i]) {
        if (!visited[adj]) {
            dfs(adj, g, visited);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool> visited(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> disconneted;    
    dfs(1, g, visited);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {  
            dfs(i, g, visited);
            disconneted.push_back(i);
        }
    }

    cout << disconneted.size() << '\n';
    for (auto d: disconneted) {
        cout << 1 << ' ' << d << '\n';
    }
}
