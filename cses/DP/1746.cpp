#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
void solve() {
    /*
        se i != 0 entao so pode chegar de i-1, i ou i + 1
        se i = 0 a gnt n sabe ele
        entao so pega de todo mundo
    */
    int n, m;
    cin >> n >> m;
    ll f[n + 1][m + 2], a[n];
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] == 0) {
        fill(f[0], f[0] + m + 2, 1);
        f[0][0] = f[0][m+1] = 0;
    } else {
        f[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != 0) {
            (f[i][a[i]] = (f[i][a[i]] + f[i - 1][a[i] - 1] + f[i - 1][a[i]] + f[i - 1][a[i] + 1])) %= mod;
        } else {
            for (int j = 1; j <= m; j++) {
                (f[i][j] = (f[i][j] + f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1])) %= mod;
            }
        }
    }
    ll ans = 0;
    for (int j =0; j <= m; j++) {
        (ans += f[n - 1][j]) %= mod;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}