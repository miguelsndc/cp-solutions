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
    while(tt--) {
        int n, k; cin >> n >> k;
        vector<int> g[n];
        map<pair<int, int>, bool> edge;
        vector<int> in_degree(n);
        int prev = -1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                int x; cin >> x; --x;
                if (j == 0) continue;
                if(prev != -1) {
                    if (edge[{prev, x}] == 0) {
                        g[prev].push_back(x);
                        edge[{prev, x}] = 1;
                        in_degree[x]++;
                    }
                }
                prev = x;
            }
            prev = -1;
        }

        if (k == 1) {
            cout << "YES\n";
            continue;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        int index = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            index++;
            for (int neighbour: g[node]) {
                in_degree[neighbour]--;
                if(in_degree[neighbour]==0) q.push(neighbour);
            }
        }

        if (index == n)  {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}