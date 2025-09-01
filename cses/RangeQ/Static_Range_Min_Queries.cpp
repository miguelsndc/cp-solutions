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
constexpr int mod = 1e9 + 7;

#ifndef CARNEDESOOOL
#define maxn 200005
#else
#define maxn 30
#endif

int n;
vector<int> tree(4 * maxn), a;

int join(int a, int b) {
    return min(a, b);
}

void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
};

int query(int a, int b, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return 1e9 + 1;
    if (l >= a and r <= b) return tree[v];
    int m = (l + r) / 2;
    return join(query(a, b, l, m, v * 2 + 1), query(a, b, m + 1, r, v * 2 + 2));
}

void solve() {
    int q;
    cin >> n >> q;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build();
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << query(a, b) << "\n";
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