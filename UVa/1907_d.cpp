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
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    ll lo = 0, hi = 1e18, ans = 1e18;
    while (lo <= hi) {
        ll m = lo + (hi - lo) / 2;
        ll l = 0, r = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            l = max(l - m, a[i].first);
            r = min(r + m, a[i].second);
            if (l > r) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = m;
            hi = m - 1;
        } else {
            lo = m + 1;
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