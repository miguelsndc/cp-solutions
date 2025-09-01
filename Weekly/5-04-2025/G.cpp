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
    int r, g;
    cin >> r >> g;

    int h = 1, dp[maxn];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i * (i + 1) / 2 <= r + g; i++) h = i;
    if (r > g) swap(r, g);
    for (int i = 1; i <= h; i++)
        for (int j = r; j >= i; j--) dp[j] = (dp[j] + dp[j - i]) % mod;

    int ans = 0;
    for (int i = 0; i <= r; i++)
        if (h * (h + 1) / 2 - i <= g) ans = (ans + dp[i]) % mod;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}