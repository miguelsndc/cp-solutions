#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mxn = 1e12;
vector<ll> fac {1};
void solve() {
    ll n; cin >> n;
    ll ans = 1e9;
    for (int b = 0; b < (1 << 16); b++) {
        ll s = 0, cnt = 0;
        for (int i = 0; i < 16; i++) {
            if (b & (1 << i)) {
                s += fac[i];
                cnt++;
            }
            if (s > n) break;
        }
        if (s <= n) {
            ans = min(ans, cnt + __builtin_popcountll(n - s));
        }
    }
    cout << ans << '\n';
}
int main() {
    ll f = 1;
    for (ll i = 1; i <= 15; i++) {
        f *= i;
        fac.push_back(f);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}