#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        g[i].push_back(v);
    }
    vector<int> visited(n + 1, 0), depth(n + 1);
    auto f = [&] (auto &&f2, int u, int d = 0) {
        depth[u] = d;
        for (int v : g[u]) {
            if (!visited[v]) {
                f2(f2, v, d + 1);
            }
        }
    };
}