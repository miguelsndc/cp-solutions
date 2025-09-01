#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<ll> a(n);
    for (ll &x : a) cin >> x;

    if (n % 2 == 0) {
        ll ans = 0;
        for (int i = 0; i < n; i += 2)
            ans = max(ans, a[i + 1] - a[i]);
        cout << ans << '\n';
        return;
    }

    /*

        pra cada par eu coloco algum cara ali na melhor posicao possivel e vejo
        se diminuiu o valor de k
    */

    ll ans = 1e18;
    // add either ai - 1 or ai + 1 and do the thing
    auto faz = [&](ll x) {
        vector<ll> b = a;
        b.push_back(x);
        sort(all(b));

        ll mx = 0;
        for (int i = 0; i + 1 < b.size(); i += 2) {
            mx = max(mx, b[i + 1] - b[i]);
        }
        ans = min(mx, ans);
    };

    for (int i = 0; i < n; i++) {
        faz(a[i] - 1);
        faz(a[i] + 1);
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