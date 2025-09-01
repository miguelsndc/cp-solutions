#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int MAXN = 2e5 + 1;

vector<int> g[MAXN];
set<int> colors[MAXN];
int ans[MAXN];

void dfs(int u, int parent) {
    for (int v: g[u]) {
        if (v != parent) {
            dfs(v, u);

       // merge small to large, make u the biggest always
            if (colors[u].size() < colors[v].size()) {
                    swap(colors[u], colors[v]);
            }

            for (int x :colors[v]) colors[u].insert(x);
        }
    }

    ans[u] = colors[u].size();
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        colors[i].insert(x);
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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