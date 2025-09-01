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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    int div = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % x == 0) div++;
    }
    if (div == n) {
        cout << -1 << '\n';
    } else if (accumulate(all(a), 0) % x != 0) {
        cout << n << '\n';
    } else {
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            if ((a[i] % x) != 0) {
                l = i;
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            if ((a[i] % x) != 0) {
                r = i;
                break;
            }
        }
        cout << max(n - l, r - 1) << '\n';
    }
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