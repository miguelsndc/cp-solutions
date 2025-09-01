#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n), b(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto check = [&] () -> ll {
        ll ans = 0, curx = 0, cury = 0;
        for (int i = 0; i < n; i++) {
            curx += a[p[i]], cury += b[p[i]];
            ans++;
            if (curx > x or cury > y) {
                break;
            } 
        }
        return ans;
    };

    sort(p.begin(), p.end(), [&](int v1, int v2) {
        return a[v1] > a[v2];
    });

    ll ans = 1e9;
    ans = min(ans, check());
    swap(a,b); swap(x,y);
    sort(p.begin(), p.end(), [&](int v1, int v2) {
        return a[v1] > a[v2];
    });
    ans = min(ans, check());
    cout << ans << '\n';
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
