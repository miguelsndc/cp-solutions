#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

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
    set<pii> s;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
    for (int i = 0; i < n; i++) s.insert(a[i]);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll dx = a[j].fi - a[i].fi;
            ll dy = a[j].se - a[i].se;
            if (s.count({a[i].fi - dy, a[i].se + dx}) and s.count({a[j].fi - dy, a[j].se + dx})) ans++;
            if (s.count({a[i].fi + dy, a[i].se - dx}) and s.count({a[j].fi + dy, a[j].se - dx})) ans++;
        }
    }
    cout << ans / 4 << '\n';
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}