#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define sz(x) (x.size())
namespace rg = std::ranges;

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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[maxn], vis(n), deg(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    auto check = [&](auto&& self, int u) -> void {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) self(self, v);
        }
    };

    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            check(check, i);
            cc++;
        }
    }

    if (cc > 1) {
        cout << "No\n";
        return;
    }

    int all2 = rg::all_of(deg, [&](int x) { return x == 2; });

    if (all2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}