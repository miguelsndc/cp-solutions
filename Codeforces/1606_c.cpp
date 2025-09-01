#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, k; cin >> n >> k;
    k++;
    vector<ll> pw(10); pw[0] = 1;
    for (int i = 1; i < 10; i++) pw[i] = 10 * pw[i - 1];
    ll num = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll can = k;
        if (i + 1 < n) can = min(can, pw[a[i+1]]/pw[a[i]] - 1); 
        num += can * pw[a[i]];
        k -= can;
    } 
    cout << num << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while (T--) solve();
}