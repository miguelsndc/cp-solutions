#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 1e5;
vector<pair<int, int>> adj[MAXN];
int color[MAXN];
bool impossible = false;
// type: 1 if same 0 if different
void dfs(int u, int c) {
    if (impossible) return;

    color[u] = c;
    for (const auto&[v, type]: adj[u]) {
        if (color[v] == -1) dfs(v, (type ? c: !c));
        else if (
            (type && (color[v] != color[u])) ||
            (!type && (color[v] == color[u]))
        ) {
            impossible = true;
            return;
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        char c; cin >> c; int u, v; cin >> u >> v;
        adj[--u].push_back({--v, (c == 'S')});
        adj[v].push_back({u, (c == 'S')});
    }

    int comp = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            comp++; dfs(i, 1);
        }
    }

    if (impossible) {
        cout << 0;
    } else {
        cout << 1;
        for (int i = 0; i < comp; i++) {
            cout << 0;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("revegetate");
    #endif
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}