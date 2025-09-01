#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int N, M; cin >> N >> M;
    vector g(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
    }
    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        pos[--k] = i;
    }
    bool ok = true;
    for (int u = 0; u < N; u++) {
        for (int v: g[u]) {
            ok &= pos[u] < pos[v];
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}