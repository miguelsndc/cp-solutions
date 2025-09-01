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

vector<ll> bit(maxn);
void add(int pos, ll val) {
    for (int i = pos + 1; i < maxn; i += (i & (-i))) bit[i] += val;
}

ll query(int k) {
    ll sum = 0;
    for (int i = k + 1; i > 0; i -= (i & (-i))) sum += bit[i];
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), diff(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    add(0, a[0]);
    for (int i = 1; i < n; i++) {
        add(i, a[i] - a[i - 1]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b, u;
            cin >> a >> b >> u;
            add(a - 1, u);
            add(b, -u);
        } else {
            ll k;
            cin >> k;
            cout << query(k - 1) << '\n';
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