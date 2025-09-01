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

int value[8], cost[8], n, x;
double prob[8];

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> cost[i] >> prob[i];
        prob[i] /= 100.0;
    }
    double dp[(1 << n)][x + 1];
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = 0;
        }
    }

    for (int spent = x; spent >= 0; spent--) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if ((spent + cost[i] > x) || mask == (mask | (1 << i))) {
                    continue;
                }
                double val = prob[i] * (dp[mask | (1 << i)][spent + cost[i]] + value[i]) + (1 - prob[i]) * dp[mask][spent + cost[i]];
                dp[mask][spent] = max(dp[mask][spent], val);
            }
        }
    }
    cout << setprecision(20) << fixed << dp[0][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}