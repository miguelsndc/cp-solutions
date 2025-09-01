#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    map<ll, ll> mp;
    ll ps = 0, cnt = 0;
    mp[0]++;
    for (int i = 0; i < n; i++) {
        ps += a[i];
        if (mp.count(ps - x)) {
            cnt += mp[ps - x];
        }
        mp[ps]++;
    }
    cout << cnt << '\n';
}
