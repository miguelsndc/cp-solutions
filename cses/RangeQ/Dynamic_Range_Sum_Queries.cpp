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

vector<ll> bit(maxn), a;

ll query(int pos) {
    ll x = 0;
    for (int i = pos + 1; i > 0; i -= (i & (-i))) x += bit[i];
    return x;
}

void add(int pos, int val) {
    for (int i = pos + 1; i < maxn; i += (i & (-i))) bit[i] += val;
}

void _set(int pos, int val) {
    add(pos, val - a[pos]);
    a[pos] = val;
}

void solve() {
    int n, q;
    cin >> n >> q;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            _set(k - 1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(b - 1) - query(a - 2) << '\n';
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