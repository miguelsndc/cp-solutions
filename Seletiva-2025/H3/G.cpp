#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n; cin >> n;
    vector<int> g[100005];
    vector<ll> dist(100005, INT64_MAX);
    vector<bool> visited(100005);
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        if (i - d >= 1) g[i - d].push_back(i);
        if (i + d <= n) g[i + d].push_back(i);
    }

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    visited[n] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbour: g[node]) {
            if (visited[neighbour]) continue;

            visited[neighbour] = true;
            dist[neighbour] = dist[node] + 1;

            q.push(neighbour);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INT64_MAX ? -1 : dist[i]) << '\n';
    }
}

int main() 
{
    freopen("jumping.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         solve();
    }
}