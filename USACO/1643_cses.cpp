#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> ps(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ps[i + 1] = ps[i] + x;
    }
    ll min_prefix = ps[0], ans = ps[1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ps[i] - min_prefix);
        min_prefix = min(min_prefix, ps[i]);
    }
    cout << ans << '\n';
}
