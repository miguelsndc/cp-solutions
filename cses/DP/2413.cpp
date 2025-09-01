#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    ll n;
    cin >> n;
    const int mod = 1e9 + 7;
    ll a = 1, b = 1;
    for (int i = 2; i <= n; i++) {
        ll x = (2 * a + b) % mod;
        ll y = (4 * b + a) % mod;
        a = x;
        b = y;
    }
    cout << (a + b) % mod << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}