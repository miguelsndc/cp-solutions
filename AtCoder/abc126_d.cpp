#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    int n; 
    scanf("%d", &n);
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; 
        scanf("%d%d%d", &u, &v, &w);
        g[--u].push_back({--v, w & 1});
        g[v].push_back({u, w & 1});
    }

    vector<int> color(n);
    auto dfs = [&](auto &&self, int u, int p, int xorsum) -> void {
        color[u] = xorsum;
        for (auto [v, w]: g[u]) {
            if (v != p) {
                self(self, v, u, xorsum ^ w);
            }
        }
    };
    dfs(dfs, 0, -1, 0);
    for (int x: color) {
        printf("%d\n", x);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}