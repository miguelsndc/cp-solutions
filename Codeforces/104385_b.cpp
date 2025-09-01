#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    ll k;
    cin >> k;
    vector<ll> a(k);
    for (ll &x : a)
        cin >> x;

    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> ps(k + 1);
    for (int i = 0; i < k; i++) {
        a[i] %= m;
        ps[i + 1] = ps[i] + a[i];
    }

    ll full = n / k;
    ll rem = n % k;
    ll sum = full * ps[k] + ps[rem];
    ll bn = x + sum;
    ll ans = n - ((bn / m) - (x / m));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}