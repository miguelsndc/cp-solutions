#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    ll n;
    cin >> n;

    // testar com 60

    for (ll i = 2; i <= n; i++) {
        ll k = i * i * i, cur = 1 + i + i * i;
        if (cur > n) break;

        while (cur < n) {
            cur += k;
            k *= i;
        }
        if (cur == n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}