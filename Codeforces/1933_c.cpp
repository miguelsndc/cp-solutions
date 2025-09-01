#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    ll a, b, l; cin >> a >> b >> l;
    vector<ll> pow_a(21, -1), pow_b(21, -1);
    pow_a[0] = pow_b[0] = 1;
    for (int i = 1; i <= 20; i++) {
        pow_a[i] = pow_a[i - 1] * a;
        if (pow_a[i] > l) break;
    }
    for (int i = 1; i <= 20; i++) {
        pow_b[i] = pow_b[i - 1] * b;
        if (pow_b[i] > l) break;
    }

    set<ll> s;
    for (ll x = 0; x <= 20; x++) {
        for (ll y = 0; y <= 20; y++) {
            ll v = 1;
            if (pow_a[x] != -1) v *= pow_a[x];
            if (pow_b[y] != -1) v *= pow_b[y];
            if (v <= l and l % v == 0) {
                s.insert(l / v);
            }
        }
    }
    cout << s.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}