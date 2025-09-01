#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<set<int>> g(n + 1);
    int p[n + 1], d[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        g[i].insert(p[i]);
        g[p[i]].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        d[i] = g[i].size();
    }
    int comp = 0,b=0,c=0; vector<int> curr, visited(n + 1);
    auto dfs = [&] (auto &&self, int u) -> void {
        curr.push_back(u);
        visited[u] = true;
        for (int v: g[u]) {
            if (!visited[v]) {
                self(self, v);
            }
        }
    };
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            curr.clear();
            dfs(dfs, v);
            comp++;
            bool bla = false;
            for (int v: curr) {
                if (d[v] == 1) {
                    bla = true;
                    break;
                }
            }
            if (bla) {
                b++;
            } else {
                c++;
            }
        }
    }

    cout << c + min(b, 1) <<' ' << comp << "\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}