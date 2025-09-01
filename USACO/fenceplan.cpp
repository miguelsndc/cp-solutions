#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() 
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    array<int, 2> coords[n];
    for (int i = 0; i < n; i++) {
        cin >> coords[i][0] >> coords[i][1];
    }
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    vector<int> visited(n);

    int minf = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;  
            int maxx = 0, minx = INT32_MAX, maxy = 0, miny = INT32_MAX;
            while(!q.empty()) {
                int node = q.front();
                q.pop();

                maxx = max(maxx, coords[node][0]);
                maxy = max(maxy, coords[node][1]);
                minx = min(minx, coords[node][0]);
                miny = min(miny, coords[node][1]);

                for (int neighbour: g[node]) {
                    if (visited[neighbour]) continue;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        minf = min(2 * ((maxy - miny) + (maxx - minx)), minf);
    }
}
    cout << minf;
}