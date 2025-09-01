#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size(), ps = 0;

    for (int i = 0; i < min(n, m); i++) {
        if (a[i] == b[i])
            ps++;
        else
            break;
    }
    cout << n + m - (ps > 1 ? ps - 1 : 0) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}