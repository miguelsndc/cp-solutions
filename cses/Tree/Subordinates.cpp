#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

vi subtree_sz(maxn), g[maxn];

void dfs(int u, int p = -1) {
    subtree_sz[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            subtree_sz[u] += subtree_sz[v];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << subtree_sz[i] - 1 << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}