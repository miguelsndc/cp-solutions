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
    int n, m;
    cin >> n >> m;
    vector<vi> mat(n, vi(m));
    vi rows, cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (mat[i][j]) cnt++;
        }
        rows.push_back(cnt);
        cnt = 0;
    }

    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][j]) cnt++;
        }
        cols.push_back(cnt);
        cnt = 0;
    }

    auto get_ans = [&](vector<int>& a, int x) -> ll {
        int sz = a.size();
        if (sz == 0) {
            return 0LL;
        }
        ll maxans = 0LL;
        vector<vector<ll>> dp(sz + 1, vector<ll>(2));
        for (int i = 0; i < sz; i++) {
            if (a[i] == x) {
                dp[i + 1][1] = dp[i][1] + 1;
                dp[i + 1][0] = dp[i][0] + 1;
            } else if (a[i] == (x - 1)) {
                dp[i + 1][0] = 0;
                dp[i + 1][1] = dp[i][0] + 1;
            } else {
                dp[i + 1][0] = 0;
                dp[i + 1][1] = 0;
            }
            maxans = max({maxans, dp[i + 1][1], dp[i + 1][0]});
        }
        return maxans;
    };

    cout << max(get_ans(rows, m), get_ans(cols, n)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}