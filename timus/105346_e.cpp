#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    ll n, d, x; cin >> n >> d >> x;
    ll take = d * x;
    vector<ll> amount(n), taste(n), p(n);
    for (ll &i: amount) cin >> i, i = min(d, i);
    for (ll &i: taste) cin >> i;
    for (int i = 0; i < n; i++) p[i] = i;
    sort(p.begin(), p.end(), [&](int v1, int v2) {
        if (taste[v1] == taste[v2]) {
            return amount[v1] > amount[v2];
        }
        return taste[v1] > taste[v2];
    });
    ll ans = 0;
    for (int i = 0; i < n and take; i++) {
        ll am = min(take, amount[p[i]]);
        ans += am * taste[p[i]];
        take -= am;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}