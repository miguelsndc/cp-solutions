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

ll count(ll n) {
    ll res = 0;
    for (int x = 0; x <= 2; x++) {
        ll l = 0, r = 2e9;
        while (l < r) {
            ll mid = (l + r + 1) / 2;
            if (mid * (mid + x) <= n) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        res += l;
    }
    return res;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l - 1) << '\n';
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