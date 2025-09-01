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

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    map<int, int> mpy, mpx, mppos, mpneg;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mpy[y]++;
        mpx[x]++;
        mppos[x - y]++;
        mpneg[x + y]++;
    }
    ll ans = 0;
    for (auto [_, cnt] : mpy) {
        ans += 1LL * cnt * (cnt - 1);
    }
    for (auto [_, cnt] : mpx) {
        ans += 1LL * cnt * (cnt - 1);
    }
    for (auto [_, cnt] : mppos) {
        ans += 1LL * cnt * (cnt - 1);
    }
    for (auto [_, cnt] : mpneg) {
        ans += 1LL * cnt * (cnt - 1);
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