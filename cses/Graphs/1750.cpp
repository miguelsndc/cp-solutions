#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector
const int maxn = 2e5 + 10, maxd = 32;
int par[maxn][maxd];
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> par[i][0];
    }

    for (int k = 1; k < maxd; k++) {
        for (int i = 1; i <= n; i++) {
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }

    while (q--) {
        int a, d;
        cin >> a >> d;
        for (int i = 0; i < maxd; i++) {
            if (d & (1 << i)) {
                a = par[a][i];
            }
        }
        cout << a << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}