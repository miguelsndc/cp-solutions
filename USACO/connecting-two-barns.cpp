#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int MAXN = 1E5;
vector<int> g[MAXN];
vector<int> comps[MAXN];
int n, m; int comp[MAXN];

void dfs(int idx, int i) {
    if (comp[i] != -1) {return;};
    comp[i] = idx;
    for (int v: g[i]) { dfs(idx, v); }
}

ll cost(int a, int b) {
    int dist = MAXN;
    for (int u: comps[a]) {
        int i = lower_bound(begin(comps[b]), end(comps[b]), u) - begin(comps[b]);
        if (i > 0) { dist = min(dist, abs(comps[b][i - 1] - u));};
        if (i < comps[b].size()) {dist = min(dist, abs(comps[b][i] - u));};
    }
    return (ll)dist * dist;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        comp[i] = -1;
        g[i].clear();
        comps[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1) dfs(++cur, i);
    }

    for (int i = 0; i < n; i++) {
        comps[comp[i]].push_back(i);
    }

    ll min_cost = cost(comp[0], comp[n-1]);
    for (int c = 1; c < cur; c++) {
        min_cost = min(min_cost, cost(c, comp[0]) + cost(c, comp[n - 1]));
    }

    cout << min_cost << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}