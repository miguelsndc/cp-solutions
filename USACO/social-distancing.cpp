#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

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

#define x first
#define y second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(all(a));

    auto check = [&](ll mid) -> int {
        int placed = 0;
        ll cur = a[0].x;
        for (int i = 0; i < m and placed < n; i++) {
            while (cur <= a[i].y and placed < n) {
                cur = max(a[i].x, min(cur, a[i].y));
                placed++;
                cur += mid;
            }
        }

        return placed == n;
    };

    ll lo = 0, hi = 1e18, ans = 1e18;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}