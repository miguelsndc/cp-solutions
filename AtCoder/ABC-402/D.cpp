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
const double pi = acos(-1.0);

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) % n]++;
    }
    i64 ans = 1LL * m * (m - 1) / 2;
    for (auto [_, x] : cnt) {
        ans -= 1LL * x * (x - 1) / 2;
    }
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