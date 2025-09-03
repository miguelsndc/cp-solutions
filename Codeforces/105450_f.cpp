#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    vector<int> par(n), sub(n);
    vector tree(n, vector<int>());
    for (int i =0; i < n; i++) {
        int x; cin >> x;
        par[i] = x & 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }

    auto get_xor = [&] (auto&&self, int u, int p = -1) -> int {
        sub[u] = par[u];
        for (int v: tree[u]) {
            if (v != p) {
                sub[u] ^= self(self, v, u);
            }
        }
        return sub[u];
    };
    get_xor(get_xor, 0, -1);

    if (sub[0] == 1) {
        cout << -1 << '\n';
        return;
    }

    int ans = count(sub.begin(), sub.end(), 0);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}