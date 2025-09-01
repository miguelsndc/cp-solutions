#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll &x: a) cin >> x;
        ll q; cin >> q;
        map<ll,ll> cnt;
        for (int x: a) cnt[x]++;
        n = a.size();
        while(q--) {
            ll x, y; cin >>x >> y;
            ll d = x * x - 4 * y;
            if (d < 0) {
                cout << 0 << ' ';
                continue;
            }
            ll sq = sqrtl(d);
            if (sq * sq != d) {
                cout << 0 << ' ';
                continue;
            } 
            ll r1 = (x - sq) / 2;
            ll r2 = (x + sq) / 2;
            if (r1 != r2) {
                cout << cnt[r1] * cnt[r2] << ' ';
            } else {
                cout << (cnt[r1] * (cnt[r1] - 1)) / 2 << ' ';
            }
        }
        cout << '\n';
    }
}