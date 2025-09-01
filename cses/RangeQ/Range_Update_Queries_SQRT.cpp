#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

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
    int n, q;
    cin >> n >> q;
    int len = sqrt(n + .0) + 1;
    vector<ll> b(len), a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            --l, --r;

            int bl = l / len, br = r / len;

            if (bl == br) {
                for (int i = l; i <= r; i++) {
                    a[i] += u;
                }
            } else {
                for (int i = l, end = (bl + 1) * len - 1; i <= end; i++) {
                    a[i] += u;
                }
                for (int i = bl + 1; i <= br - 1; i++) {
                    b[i] += u;
                }
                for (int i = br * len; i <= r; i++) {
                    a[i] += u;
                }
            }
        } else {
            int k;
            cin >> k;
            --k;
            cout << a[k] + b[k / len] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}