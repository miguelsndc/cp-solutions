#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 1e5 + 5;
// maior caminho começando no nó i 
vi dp(MAXN, 0);
vi g[MAXN];

void dfs(int u, vi &visited) {
    visited[u] = true;
    for (int v: g[u]) {
        if (!visited[v]) {
            dfs(v, visited);
        }
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    vi vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, vis);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dp[i]);
    }
    cout << mx;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}