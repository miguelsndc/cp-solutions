#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int maxn = 1e4 + 1;
vector<bool> vis(maxn);
vector<int> g[maxn];

void dfs(int u, int p) {
    vis[u] = true;
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int u = 1; u <= n; u++) {
        int v; cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            c++; dfs(i, -1);
        }
    }
    cout << c;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    int tt = 1; // cin >> tt;
    cin.tie(0);
    while(tt--) {
         solve();
    }
}