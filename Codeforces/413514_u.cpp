#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    i64 n, h;
    cin >> n >> h;
    vector<i64> a(n);
    for (i64& x : a) cin >> x;
    i64 lo = 0, hi = 1e18, ans = 1e18;
    while (lo <= hi) {
        i64 m = lo + (hi - lo) / 2;

        // can he kill it if poison lasts m rounds
        i64 dmg = 0;
        for (int i = 0; i < n - 1; i++) {
            i64 diff = a[i + 1] - a[i];
            dmg += min(diff, m);
        }
        dmg += m;  // effects after last second

        if (dmg >= h) {
            ans = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}