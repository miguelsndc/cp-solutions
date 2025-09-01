#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define writeln(x) cout << x << '\n';

const int maxn = 2e5 + 5;
const int INF = 1e18;

void solve() {
    int n, s1, s2; cin >> n >> s1 >> s2;
    vi g1[1005], g2[1005];
    vi good(1005);
    vector<vi> dist(n, vi(n, INF));
    s1--, s2--;
    set<ii> edges;
    int m1; cin >> m1;
    fori(m1) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        edges.insert({u, v});
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    int m2; cin >> m2;
    fori(m2) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        if (edges.count({u, v})) {
            good[u] = good[v] = true;
        }
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    set<pair<int, ii>> pq;
    pq.insert({0, {s1, s2}});
    dist[s1][s2] = 0;
    while(!pq.empty()) {
        auto [u, v] = pq.begin()->second;
        pq.erase(pq.begin());
        for (auto to1: g1[u]) {
            for (auto to2: g2[v]) {
                int w = abs(to2 - to1);
                if (dist[to1][to2] > dist[u][v] + w) {
                    pq.erase({dist[to1][to2], {to1, to2}});
                    dist[to1][to2] = dist[u][v] + w;
                    pq.insert({dist[to1][to2], {to1, to2}});
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans = min(ans, dist[i][i]);
        }
    }
    ans = (ans == INF ? -1 : ans);
    writeln(ans);
}

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
}