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
    int l, r;
    cin >> l >> r;
    // msb diferente
    int k = 31 - __builtin_clz(l ^ r);
    // l or (011111....) ate o msb diferente -1
    // b = a + 1 <= r e todos bits != a
    // c pd ser qlqr coisa q n seja os 2
    int a = l | ((1 << k) - 1), b = a + 1, c = (a == l ? r : l);
    cout << a << " " << b << " " << c << "\n";
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