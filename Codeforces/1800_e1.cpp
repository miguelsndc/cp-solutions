#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector g(n, vector<int>());
    for (int i = 0; i < n; i++) {
        if (i + 3 < n) {
            g[i].push_back(i + 3);
            g[i + 3].push_back(i);
        }
        if (i + 4 < n) {
            g[i].push_back(i + 4);
            g[i + 4].push_back(i);
        }
    }

    vector<int> comp, vis(n);
    vector<vector<int>> comps;
    auto dfs = [&](auto&& f, int u) -> void {
        vis[u] = true;
        comp.push_back(u);
        for (int v : g[u]) {
            if (!vis[v]) {
                f(f, v);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            comp.clear();
            dfs(dfs, i);
            comps.push_back(comp);
        }
    }

    for (auto c : comps) {
        vector<int> freqa(26), freqb(26);
        for (int x : c) {
            freqa[a[x] - 'a']++;
            freqb[b[x] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freqa[i] != freqb[i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}