#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;
ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a, ll p){
    return fexp(a, p - 2);
}
const int mxn = 1e6 + 5;
ll fact[mxn]; 
ll comb(ll n, ll k, ll p) {
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}
int32_t main() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < mxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<ll> sections(m);
    for (ll &x:sections) cin >> x;
    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ll x = comb(sections[i], n, mod) % mod;
        ans = (ans * x) % mod;
    }
    cout << ans % mod << '\n';
}
