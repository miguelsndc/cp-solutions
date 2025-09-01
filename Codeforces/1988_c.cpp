#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    ll n;
    cin >> n;
    vc<ll> a;
    for (int i = 62; i >= 0; i--) {
        ll x = 1LL << i;
        if (((x & n) == x) and (x != n)) {
            a.push_back(n - x);
        }
    }
    a.push_back(n);
    cout << a.size() << '\n';
    for (ll x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}