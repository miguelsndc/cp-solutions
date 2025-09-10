#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, m; cin >> n >> m;
    vector g(n + 1, vector<int>());
    vector<int> vai(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (u > v) swap (u, v);
        if (u == 1) vai[v] = true;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n + 1);
    for (int node = 2; node <= n; node++) {
        if (vai[node]) {
            for (int v: g[node]) {
                c[v]++;
            }
        }
    }

    ll ans = 0;
    for (int node = 2; node <= n; node++) {
        if (c[node] > 1) {
            for (int v: g[node]) {
                if (vai[v]) ans += c[node] - 1;
            }
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