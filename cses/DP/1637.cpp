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
    vector<int> f(n + 1, 100000000);
    f[0] = 0;
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k > 0) {
            int m = k % 10;
            k /= 10;
            if (i - m >= 0)
                f[i] = min(f[i], f[i - m] + 1);
        }
    }
    cout << f[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}