#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ps(n + 1);
        for (int i = 0; i < n; i++) {
            int x = (int)(s[i] - '0');
            ps[i + 1] = ps[i] + x;
        }
        map<int, ll> mp;
        for (int i = 0; i <= n; i++) {
            mp[ps[i] - i]++;
        }
        ll ans = 0;
        for (auto [x, c]: mp) {
            ans += c * (c - 1) / 2;
        }
        cout << ans << '\n';
    }
}
