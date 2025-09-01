#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int&i: a) cin >> i;
    ll sum = accumulate(all(a), 0LL);
    map<ll,ll> mp;
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        ll y = 1ll * n * a[j];
        ans += mp[2 * sum - y];
        mp[y]++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}