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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n, vector<int>(m));
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = cnt;
            cnt = cnt % k + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (m % k == 0 and (i & 1)) {
            for (int j = 1; j < m; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << ans[i][0] << ' ';
        } else {
            for (int x : ans[i]) {
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
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