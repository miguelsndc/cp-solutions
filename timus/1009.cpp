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

ll n, k;
ll f(int i, int zero) {
    if (i > n) return 1;
    ll ans = 0;
    if (zero)
        ans += (k - 1) * f(i + 1, false);
    else {
        ans += k * f(i + 1, true);
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    vector<ll> dp0(n + 1), dp1(n + 1);
    dp0[1] = k - 1;
    dp1[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp0[i] = (dp0[i - 1] + dp1[i - 1]) * (k - 1);
        dp1[i] = dp0[i - 1];
    }
    cout << dp0[n] + dp1[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}