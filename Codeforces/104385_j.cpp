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
    vector<int> b(n + 1), has(n + 1, -1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        int a, bi;
        if (t == 0) {
            cin >> a >> bi;
            b[a] = min(b[a], bi);
        } else {
            cin >> a;
            int sqr = sqrt(n), mn = 1e9;
            for (int i = max(1, a - sqr); i <= min(a + sqr, n); i++) {
                mn = min(mn, (a - i) * (a - i) + b[i]);
            }
            cout << mn << '\n';
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