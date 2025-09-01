#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    int c = 1;
    while(tt--)  {
        int n, m; cin >> n >> m;
        vector<int> g[n];
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> coloring(n, -1);
        bool bipartite = true;
        for(int i = 0; i < n; i++) {
            if (coloring[i] != -1) continue;
            queue<int> q;
            q.push(i);
            coloring[i] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                if (!bipartite) break;

                for (int neighbour: g[node]) {
                    if (coloring[neighbour] == -1) {
                        coloring[neighbour] = 1 - coloring[node];
                        q.push(neighbour);
                    } else if (coloring[node] == coloring[neighbour]) {
                        bipartite = false;
                    }
                }
            }

            if(!bipartite) break;
        }

        cout << "Scenario #" << c << ':' << '\n';
        if (bipartite) {
            cout << "No suspicious bugs found!\n";
        } else {
            cout << "Suspicious bugs found!\n";
        }
        c++;
    }
}