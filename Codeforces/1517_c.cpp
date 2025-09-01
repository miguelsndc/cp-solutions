#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

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
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> ans[i][i];
    }

    function<void(int, int, int, int)> dfs = [&](int i, int j, int val, int cnt) {
        if (j - 1 >= 0 and ans[i][j - 1] == 0 and cnt > 0) {
            ans[i][j - 1] = val;
            dfs(i, j - 1, val, cnt - 1);
        } else if (i + 1 < n and ans[i + 1][j] == 0 and cnt > 0) {
            ans[i + 1][j] = val;
            dfs(i + 1, j, val, cnt - 1);
        }
    };

    for (int i = 0; i < n; i++) {
        dfs(i, i, ans[i][i], ans[i][i] - 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
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