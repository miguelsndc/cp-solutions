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
    i64 n;
    cin >> n;
    i64 l = 0, r = 1e9, ans = 0;
    while (r - l > 1) {
        i64 m = (l + r) / 2;
        if (m * m * 2 <= n)
            l = m;
        else
            r = m;
    }
    ans += l;
    l = 0, r = 1e9;
    while (r - l > 1) {
        i64 m = (l + r) / 2;
        if (m * m * 4 <= n)
            l = m;
        else
            r = m;
    }
    ans += l;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}