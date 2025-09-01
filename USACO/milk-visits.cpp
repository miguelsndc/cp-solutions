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

string s;
const int MAXN = 1e5;
vector<int> g[MAXN];
vector<int> components(MAXN, -1);

void dfs(int u, int parent, int comp, char ch) {
    components[u] = comp;
    for (int x: g[u]) {
        if (x != parent && s[x] == ch) {
            dfs(x, u, comp, ch);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    cin >> s;
    for (int i = 0; i <  n - 1; i++) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int curr = 0;
    for (int i = 0; i < n - 1; i++) {
        if (components[i] == -1) {
            dfs(i, -1, curr, s[i]);
            curr++;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b; char c; cin >> a >> b >> c;
        --a, --b;
        if (components[a] == components[b] && c != s[a]) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("milkvisits");
    #endif
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}