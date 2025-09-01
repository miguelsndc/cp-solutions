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
    vector<unsigned int> a(n), pxor(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) pxor[i + 1] = pxor[i] ^ a[i];
    unsigned int x0 = 0, x1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            x0 ^= a[i];
        } else {
            x1 ^= a[i];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            x1 ^= (pxor[r] ^ pxor[l - 1]);
            x0 ^= (pxor[r] ^ pxor[l - 1]);
        } else {
            int g;
            cin >> g;
            if (g)
                cout << x1 << ' ';
            else
                cout << x0 << ' ';
        }
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