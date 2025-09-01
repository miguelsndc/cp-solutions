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
    ll x;
    cin >> x;
    int sz = to_string(x).size();

    bool is_pow_10 = true;
    while (x) {
        int k = x % 10;
        if (x > 10 and k != 0) {
            is_pow_10 = false;
        } else if (x < 10 and x != 1) {
            is_pow_10 = false;
        }
        x /= 10;
    }

    if (is_pow_10) {
        cout << -1 << '\n';
        return;
    }

    cout << 1;
    for (int i = 0; i < sz; i++) {
        cout << 0;
    }
    cout << '\n';
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