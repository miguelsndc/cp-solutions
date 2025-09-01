#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define fi first
#define se second

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
    vi a(m);
    for (int& x : a) cin >> x;
    sort(all(a));
    ll ans = 0;
    for (int k = 1; k <= n - 1; k++) {
        ll c1 = m - (lower_bound(all(a), k) - begin(a));
        ll c2 = m - (lower_bound(all(a), n - k) - begin(a));
        ans += c1 * c2 - min(c1, c2);
    }
    cout << ans << '\n';
}

int main() {
    fast;
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}