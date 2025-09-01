#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector
const int mod = 998244353;

ll fexp(ll a, ll b, ll MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a, ll p) {
    return fexp(a, p - 2, mod);
}
const int maxn = 1e6 + 10;
ll fact[maxn];  // Preh computar fatoriais
ll comb(ll n, ll k, ll p) {
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}

void solve() {
    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        ll ans = comb(n + 1, k + 1, mod);
        cout << ans << '\n';
    }
}

int32_t main() {
    fact[0] = 1;
    for (ll i = 1; i < maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}