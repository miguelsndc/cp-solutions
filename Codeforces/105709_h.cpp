#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
const int mxn = 3e5 + 5;
vector<int> g[mxn];
int tin[mxn], low[mxn];
vector<int> bridges;
int timer = 1;
map<pair<int,int>, vector<int>> mp;
void dfs(int u, int p) {
    tin[u] = timer++;
    low[u] = tin[u];
    int ch = 0;
    for (int v : g[u])
        if (v != p) {
            if (tin[v])  
                low[u] = min(tin[v], low[u]);
            else {
                dfs(v, u);
                low[u] = min(low[v], low[u]);
                if (tin[u] < low[v]) {
                    vector<int> & a = mp[minmax(u, v)];
                    if (a.size() == 1) {
                        for (int x: a) { 
                            bridges.push_back(x);
                        }
                    }
                }
            }
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0;i < m; i++) {
        int id, u, v; cin >> id >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[minmax(u,v)].push_back(id); 
    }
    dfs(0, -1);
    sort(bridges.begin(), bridges.end());
    if (bridges.size() > 0) {
        for (int id: bridges) {
            cout << id << ' ';
        }
    } else {
        cout << -1 << '\n';
    }
}