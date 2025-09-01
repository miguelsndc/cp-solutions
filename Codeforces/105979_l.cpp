#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ll ans = 0;
string s;
const int mxn = 1e6 + 10, inf = 1e6 + 9;
int removed[mxn]{0}, sz[mxn]{0};
vector<int> g[mxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v != p and !removed[v]) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

int centroid(int u, int p, int n) {
    for (int v : g[u]) {
        if (v != p and !removed[v] and sz[v] * 2 > n)
            return centroid(v, u, n);
    }
    return u;
}

void go(int u, int p, int bal, int min_pref, bool filling, map<int, int>& cnt) {
    if (s[u] == '(')
        bal++;
    else
        bal--;

    min_pref = min(min_pref, bal);

    if (!filling and min_pref >= 0) {
        cnt[bal]++;
    } else if (min_pref >= bal and filling)
        ans += cnt[-bal];

    for (int v : g[u]) {
        if (v != p && !removed[v]) {
            go(v, u, bal, min_pref, filling, cnt);
        }
    }
}

void decomp(int u) {
    get_sz(u, -1);
    int c = centroid(u, -1, sz[u]);
    removed[c] = true;
    int bal_c = (s[c] == '(' ? 1 : -1);
    map<int, int> cnt;
    cnt[0] = 1;
    for (int v : g[c]) {
        if (removed[v]) continue;
        go(v, c, 0, 0, false, cnt);
    }
    for (int v : g[c]) {
        if (removed[v]) continue;
        go(v, c, bal_c, min(0, bal_c), true, cnt);
    }
    for (int v : g[c]) {
        if (!removed[v]) decomp(v);
    }
}
void solve() {
    int n;
    cin >> n;
    cin >> s;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    decomp(0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}