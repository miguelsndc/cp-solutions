#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    ll mx = *max_element(all(a));
    ll l = 0, r = 1e9 + 5, ans = mx;
    auto check = [&](ll mx) -> bool {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            ll used = 0, ultimobom = true;
            for (int j = i; j < n; j++) {
                // a[j] deve ser pelo menos mx - 1 pra conseguir setar a[i] pra mx 
                ll quero = mx - (j - i);
                if (a[j] >= quero) {
                    break;
                } else if (j == n - 1) {
                    ultimobom &= a[j] >= quero;
                } else {
                    used += quero - a[j];
                } 
            }
            ok |= (used <= k) and ultimobom;
        }
        return ok;
    };
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while (T--) solve();
}