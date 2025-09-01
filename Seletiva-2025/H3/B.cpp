#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define MOD 1000000007

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> g[n];
    vector<int> in_degree(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        in_degree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int index = 0;
    vector<int> order(n);
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        order[index++] = node;

        for(int adj: g[node]) {
            in_degree[adj]--;
            if (in_degree[adj] == 0) {
                q.push(adj);
            }
        }
    }

    if (index < n) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 0; i < order.size() - 1; i++) {
        cout << order[i] + 1 << ' ';
    }
    cout << order[order.size() - 1] + 1;
}