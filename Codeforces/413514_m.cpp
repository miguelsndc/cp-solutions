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

vector<i64> bit(maxn + 100), a(maxn);
void solve() {
    int n, q;
    cin >> n >> q;
    map<i64, i64> mp;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        mp[i + 1] = x;
        sum += x;
    }

    int num = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            i64 i, x;
            cin >> i >> x;
            if (mp.count(i)) {
                sum -= mp[i];
                sum += x;
            } else {
                sum -= num;
                sum += x;
            }
            mp[i] = x;
            cout << sum << '\n';
        } else {
            i64 x;
            cin >> x;
            num = x;
            sum = x * n;
            mp.clear();
            cout << sum << '\n';
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