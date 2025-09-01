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

int n;
vi tree, a;

void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

int query(int a, int b, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return 1e9 + 1;
    if (l >= a and r <= b) return tree[v];
    int m = (l + r) / 2;
    return min(query(a, b, l, m, v * 2 + 1), query(a, b, m + 1, r, v * 2 + 2));
}

void update(int pos, int val, int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(pos, val, l, m, v * 2 + 1);
        } else {
            update(pos, val, m + 1, r, v * 2 + 2);
        }
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

void solve() {
    int q;
    cin >> n >> q;
    tree.assign(4 * n, 0);
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << query(a, b) << "\n";
        }
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