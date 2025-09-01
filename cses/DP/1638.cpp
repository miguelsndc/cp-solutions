#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    const int mod = 1e9 + 7;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector f(n, vector<int>(n));
    f[0][0] = (grid[0][0] != '*');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;

            if (i - 1 >= 0 and grid[i - 1][j] != '*')
                f[i][j] = (f[i][j] + f[i - 1][j]) % mod;
            if (j - 1 >= 0 and grid[i][j - 1] != '*')
                f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
            f[i][j] %= mod;
        }
    }
    cout << f[n - 1][n - 1] % mod << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}