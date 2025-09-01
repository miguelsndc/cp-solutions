#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {	
    int n, l; cin >> n >> l;
    if (l % 3 != 0) {
        cout << 0 << '\n';
        return;
    }
    vector<int> d(n - 1), points(n);
    for (int &i: d) cin >> i;
    for (int i = 1; i < n; i++) {
        points[i] = (points[i - 1] + d[i - 1]) % l;
    }
    map<ll,ll> mp;
    sort(all(points));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a = (points[i] - l / 3 + l) % l;
        int b = (points[i] - 2 * l / 3 + l) % l;
        if (mp.count(a) and mp.count(b)) {
            ans += mp[a] * mp[b];
        }
        mp[points[i]]++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}