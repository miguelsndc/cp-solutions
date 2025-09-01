#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

void solve() {
    ll n;
    cin >> n;
    ll k[n];
    for (ll i = 0; i < n; i++) cin >> k[i];

    ll lc = 1;
    for (ll i = 0; i < n; i++) {
        lc = lcm(lc, k[i]);
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += lc / k[i];
    }
    if (sum < lc) {
        for (ll i = 0; i < n; i++) {
            cout << lc / k[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}