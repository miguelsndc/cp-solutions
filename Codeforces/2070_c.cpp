#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define fi first
#define se second

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    for (int& x : a) cin >> x;

    auto dale = [&](ll m) -> bool {
        // can i paint cells > correctly ?
        int cur = 0, curmax = 0, paints = 0;
        for (int i = 0; i < n; i++) {
            // paro qnd encontro vermelho > k e começo qnd encontro azul > k
            if ((s[i] == 'B' and a[i] > m) || (cur > 0 and a[i] <= m)) {
                cur++;
            }

            if (s[i] == 'R' and a[i] > m and cur > 0) {
                cur = 0;
                paints++;
            }
        }
        paints += (cur > 0);
        return (paints <= k);
    };

    ll l = 0, r = *max_element(all(a)), ans = *max_element(all(a));

    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (dale(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    fast;
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}