#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int& x : a) {
        cin >> x;
        x--;
    }
    for (int& x : b) {
        cin >> x;
        x--;
    }

    vector<int> g[n], vis(n);
    for (int i = 0; i < n; i++) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    function<void(int)> dfs = [&](int cur) {
        vis[cur] = true;
        for (int v : g[cur]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans *= 2;
            ans %= mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}