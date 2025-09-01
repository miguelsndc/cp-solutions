#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> g(n + 1);
    int a, b, w;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> w;
        g[a] ^= w;
        g[b] ^= w;
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            g[x] ^= z;
            g[y] ^= z;
        } else {
            int x;
            cin >> x;
            cout << g[x] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}