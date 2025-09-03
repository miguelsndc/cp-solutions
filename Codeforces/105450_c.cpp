#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    vector<ll> l(n);
    map<ll,ll> freq;
    for (ll &i: l) cin >> i, freq[i]++;
    ll ans = 0;
    ll mx = 1ll * (*max_element(l.begin(), l.end()));
    for (int i = 0; i < n; i++) {
        ll cur = l[i], cnt = 0;
        while(cur <= mx) {
            cnt += freq[cur];
            cur *= 2;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}