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

int join(int a, int b) {
    return max(a, b);
}

int lc(int v) {
    return v * 2 + 1;
}
int rc(int v) {
    return v * 2 + 2;
}

void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(l, m, lc(v));
        build(m + 1, r, rc(v));
        tree[v] = join(tree[lc(v)], tree[rc(v)]);
    }
}

void query(int k, int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] -= k;
        cout << l + 1 << ' ';
    } else {
        int m = (l + r) / 2;

        if (tree[lc(v)] >= k)
            query(k, l, m, lc(v));
        else
            query(k, m + 1, r, rc(v));

        tree[v] = join(tree[lc(v)], tree[rc(v)]);
    }
}

void solve() {
    int q;
    cin >> n >> q;
    tree.assign(4 * n, 0);
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build();
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (tree[0] < x) {
            cout << 0 << " ";
        } else {
            query(x);
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