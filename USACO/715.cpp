#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b; cin >> n >> k >> b;
    vector<ll> signals(n + 1);
    for (int i = 0; i < b; i++) {
        int x; cin >> x;
        signals[x]++;
    }
    for (int i = 1; i <= n; i++) {
        signals[i] += signals[i - 1];
    }
    ll ans = n;
    for (int i = k; i <= n; i++) {
        ans = min(ans, signals[i] - signals[i - k]);
    }
    cout << ans << '\n';
}
