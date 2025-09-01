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
    ll n;
    cin >> n;
    ll ans = 20, cur = 10;

    auto check7 = [&](ll x) {
        while (x) {
            if ((x % 10) == 7) return true;
            x /= 10;
        }
        return false;
    };

    if (check7(n)) {
        cout << 0 << '\n';
        return;
    }

    for (ll i = 0; i < 14; i++) {
        ll val = cur - 1;
        for (ll j = 1; j < ans; j++) {
            if (check7(n + val * j)) {
                ans = j;
                break;
            }
        }
        cur *= 10;
    }

    cout << ans << "\n";
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