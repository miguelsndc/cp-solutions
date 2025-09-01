#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<int> a(n);
    for (int &x : a) cin >> x;
    ll sum = accumulate(all(a), 0LL);
    ll alt = 0;
    for (int &x : a) {
        alt += (x == 1) ? 2 : 1;
    }
    cout << (((n > 1) and sum >= alt) ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}