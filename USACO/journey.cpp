#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int MAXN = 1e5 + 1;

vector<bool> visited(MAXN);
vector<int> g[MAXN];

ld ximirapeixola = 0;
void dfs(int u, int depth, ld prob) {
    visited[u] = true;
    int possible = 0;
    for (int v: g[u]) {
        if (!visited[v]) { possible++; }
    }

    if (possible == 0) {
        ximirapeixola += depth * prob;
    } else {
        ld newprob = prob / possible;
        for (int v: g[u]) {
            if (!visited[v]) dfs(v, depth + 1, newprob);
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 1);
    cout << ximirapeixola;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cout << setprecision(12) << fixed;
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}