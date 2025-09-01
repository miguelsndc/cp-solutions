#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

void dfs(int i, vector<vector<int>> &g, vector<int> & visited) {
    visited[i] = true;
    for (int j = 0; j < g.size(); j++) {
        if (g[i][j] && !visited[j]) {
            dfs(j, g, visited);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, c;
    while((cin >> p >> c) && p) {
        vector<array<int, 2>> edges(c);
        vector<vector<int>> g(p, vector<int>(p));

        for (int i = 0; i < c; i++) {
            int a, b; cin >> a >> b;
            g[a][b] = true;
            g[b][a] = true;
            edges[i] = {a, b};
        }

        bool yes = false;
        for (auto edge: edges) {
            auto [a, b] = edge;

            g[a][b] = false;
            g[b][a] = false;

            vector<int> visited(p);

            dfs(0, g, visited);

            for (int i = 0; i < p; i++) {
                if (!visited[i]) {
                    yes = true;
                    break;
                }
            }
            
            g[a][b] = true;
            g[b][a] = true;

            if (yes) break;
        }

        if (yes) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}