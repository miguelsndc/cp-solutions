#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() 
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    array<int, 3> v[n];
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {--a, --b, c};
    }

    vector<int> g[n];
    for (int i = 0; i < n; i++) {
        auto [x1, y1, d1] = v[i];
        for (int j = 0; j < n; j++) {
            auto [x2, y2, d2] = v[j];

            int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

            if (dist <= (d1 * d1) && i != j) {
                g[i].push_back(j);
            }
        }
    }

    int maxs = 0;
    for (int i = 0; i < n; i++) {
        int start = i;
        vector<int> visited(n);

        queue<int> q;
        q.push(start);
        visited[start] = true;
        int reachable = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neighbour: g[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    reachable++;
                }
            }
        }

        maxs = max(maxs, reachable);
    }

    cout << maxs;
}