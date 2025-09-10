#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int mxn = 1e5 + 5; int r[mxn], ask[mxn] = {0}, N;
vector g(mxn, vector<int>());
bool dfs(int u, int p = -1) {
    int need = (r[u]) >= r[1];
    for (int v: g[u]) {
        if (v == p) continue;
        if (dfs(v, u)) {
            need = true;
            ask[u] = true;
        }
    }
    return need;
}
void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> r[i];
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    ask[1] = false;
    int s = 0;
    for (int i = 1; i < mxn; i++) s += ask[i];
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}