#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    const int inf = 1e9 + 1;
    vector g(n, vector<int>(n, inf)); 
    for (int i = 0; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[--u][--v] = 0;
        g[v][u] = w;
    }
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] != inf) mx = max(mx, g[i][j]);
        }
    }
    cout << mx << '\n';
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
