#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector
const int mxn = 2e2 + 10;
int cnt[mxn]{1}, mx_depth, removed[mxn]{0}, sz[mxn]{0};
vc<int> g[mxn];

ll ans = 0, k = 0;
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
        if (v != p and !removed[v] and sz[v] > n / 2)
            return centroid(v, u, n);
    }
    return u;
}

void collect(int u, int p, int d, bool filling) {
    if (d > k) return;
    mx_depth = max(mx_depth, d);
    if (filling)
        cnt[d]++;
    else
        ans += cnt[k - d];
    for (int v : g[u]) {
        if (v != p and !removed[v]) {
            collect(v, u, d + 1, filling);
        }
    }
}

void decomp(int u) {
    get_sz(u, -1);
    int c = centroid(u, -1, sz[u]);
    removed[c] = true;
    mx_depth = 0;
    for (int v : g[c]) {
        if (removed[v]) continue;
        collect(v, c, 1, false);
        collect(v, c, 1, true);
    }
    fill(cnt + 1, cnt + mx_depth + 1, 0);
    for (int v : g[c]) {
        if (!removed[v]) decomp(v);
    }
}

void solve() {
    int n;
    cin >> n >> k;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    decomp(1);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}