#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

/*

dada uma matriz nxm calcule
a soma da diferença de valor absoluto entre todos os pares
pra todo 1 <= i < j <= n calcule soma de abs(m[i][k] - m[j][k]) pra todo 1 <= k <= n

n x m <= 3 * 10^5
 */

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> trp(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            trp[j][i] = a[i][j];
        }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
        sort(all(trp[i]));
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll ps = 0;
        for (int j = 0; j < m; j++) {
            ans += 1LL * trp[i][j] * j - ps;
            ps += trp[i][j];
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}