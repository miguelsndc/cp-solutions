#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, m, s, k, g; cin >> n >> m >> s >> k >> g;
    s--;
    vector adj(n, vector<int>());
    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<int> exits(n), ghost(n); 
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        exits[--x] = true;
    }
    for (int i = 0; i < g; i++) {
        int x; cin >> x;
        ghost[--x] = true;
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<int> ghost_dist(n, 1e9 + 1);
    for (int i = 0; i < n; i++) {
        if (ghost[i]) {
            ghost_dist[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (ghost_dist[v] > ghost_dist[u] + 1) {
                ghost_dist[v] = ghost_dist[u] + 1;
                q.push(v);
            }
        }
    }
    vector<int> dist(n, 1e9 + 1);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        q.pop();
        int u = q.front();
        for (int v: adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } 
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] < ghost_dist[i] and exits[i]) {
            ans++;
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}