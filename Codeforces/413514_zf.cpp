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

i64 ceil2(i64 a, i64 b) {
    i64 c = a / b;
    if (a % b != 0) c++;
    return c;
}

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    i64 n, k, x;
    if (n == 1) {
        cout << 1 << '\n';
        cin >> n >> k >> x;
        return;
    }
    vector<i64> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    i64 cur = a[0], groups = 1;
    vector<i64> v;
    for (int i = 0; i < n; i++) {
        if (a[i] - cur > x) {
            groups++;
            // cost to connect
            // a[i] - cur is the difference that is > x
            // (a[i] - cur) / x
            i64 diff = ceil2(a[i] - cur, x);
            v.push_back(diff - 1);
        }
        cur = a[i];
    }
    sort(all(v));
    for (i64 val : v) {
        if (val <= k) {
            groups--;
            k -= val;
        }
    }
    cout << max(groups, 1LL) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}