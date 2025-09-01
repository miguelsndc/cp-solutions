#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector g(N + 1, vector<int>());
    vector<int> dp(N + 1, 0), deg(N + 1);
    dp[1] = 1;
    int x, y;
    while((cin >> x >> y) and x and y) {
        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> q;
    for (int u = 1; u <= N; u++) {
        if (deg[u] == 0) q.push(u);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            dp[v] += dp[u];
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << dp[N] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}