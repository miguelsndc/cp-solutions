#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    bool ok = true;
    vector<vector<int>> g(n); 
    vector<int> freq(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; --x, --y;
        if (x == y) ok = false;
        freq[x]++, freq[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (freq[i] > 2) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    } 

    vector<int> color(n, -1), visited(n);
    
    auto dfs = [&](auto && self, int u, int c) {
        color[u] = c;
        bool works = true;
        for (int v: g[u]) {
            if (color[v] == color[u]) {
                return false;
            }
            if (color[v] == -1) {
                works = self(self, v, c ^ 1);
            }
        }
        return works;
    };

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            ok &= dfs(dfs, i, 0);
        }
    }

    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
} 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  cin >> T;
    while(T--) solve();
}