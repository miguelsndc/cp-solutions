#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, inp;
    cin >> n;
    multiset<ll> r;
    vector<ll> c(n), l(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> inp, r.insert(inp);
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(rall(l));
    sort(rall(c));
    vector<ll> d;
    for (int i = 0; i < n; i++) {
        auto id = r.lower_bound(l[i]);
        d.push_back(*id - l[i]);
        r.erase(id);
    }
    sort(all(d));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i] * c[i];
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