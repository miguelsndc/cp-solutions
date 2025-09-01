#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define read(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<ll> d(n);
    read(d, n);
    sort(all(d));
    ll cost = 0, ps = 0;
    for (ll i = 0; i < n; i++) {
        if (i == 2) {
            cost -= d[i];
        } else if (i > 2) {
            ps += d[i - 2];
            cost -= d[i];
            cost += (ps - (i - 2) * d[i]);
        }
    }
    cout << cost << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}