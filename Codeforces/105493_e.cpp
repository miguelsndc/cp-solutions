#include <bits/stdc++.h>
#define array vector
#define scan cin
#define print cout
#define ll long long
using namespace std;

const int inf = 1e6;
const int mxn = 2e5+5;
const int LOG = 22;
int n, q;
int tin[mxn], tout[mxn];
vector<vector<int>>up; 
vector<int> g[mxn];
int lvl[mxn];
int timer = 0;
void dfslca(int u, int p){
    tin[u] = ++timer;
    lvl[u] = lvl[p]+1;
    up[u][0] = p;
    for(int i = 1; i <= LOG; i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int v : g[u]){
        if(v!=u && !tin[v])
            dfslca(v,u);
    }
    tout[u] = ++timer;
}
 
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int a, int b){
    if(is_ancestor(a,b)) return a;
    if(is_ancestor(b,a)) return b;
    for(int i = LOG; i >= 0; i--){
        if(!is_ancestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}


void solve() {
    int n, m; scan >> n >> m;
    int tm, tk; scan >> tm >> tk;
    up.assign(mxn, vector<int>(LOG + 1));
    array<int> in(n + 1);
    array<int> meder, kylychbek;
    g[0].push_back(tm);
    g[0].push_back(tk);
    for (int i = 1; i <= m; ++i) {
        int a, b; scan >> a >> b;
        g[a].push_back(b);
        in[b]++;
    }
    dfslca(0,0);
    

    array<bool> visited(n + 1);
    function<void(int, char)> dfs = [&](int a, char p) {
        visited[a] = true;
        if (p == 'm') meder.push_back(a);
        if (p == 'k') kylychbek.push_back(a);
        if (g[a].size() == 0) return;
        if (g[a].size() == 1) {
            dfs(g[a][0], p);
            return;
        }
        int next = g[a][0];
        for (int b : g[a]) {
            int anc = lca(next, b);
            if (anc == b or anc == next) {
                next = anc;
            } else if (not visited[b]) next = b;
        }
        dfs(next, p);
    };
    dfs(tm, 'm');
    dfs(tk, 'k');
    for (int i = 1; i <= n; ++i) {
        if (not visited[i]) return void(print << "NO" << '\n');
    }
    print << "YES" << '\n';
    n = meder.size();
    print << n << '\n';
    for (int i = 0; i < n; ++i) print << meder[i] << " \n"[i + 1 == n];
    m = kylychbek.size();
    print << m << '\n';
    for (int i = 0; i < m; ++i) print << kylychbek[i] << " \n"[i + 1 == m];
}

signed main() {
    ios::sync_with_stdio(false), scan.tie(nullptr);
    solve();
    return 0;
}