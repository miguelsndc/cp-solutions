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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        r[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> r[i][j];
        }
    }
    map<int, int> mp;
    vector<int> b(n), result(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        int fades = 0;
        for (int j = 0; j < r[i].size(); j++) {
            fades = max(fades, mp[r[i][j]]);
        }
        result[fades]++;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += result[i];
        cout << cur << '\n';
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