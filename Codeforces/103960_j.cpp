#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    int mx, my, jx, jy;
    cin >> jx >> jy;
    cin >> mx >> my;

    int jp = jx + jy;
    int mp = mx + my;

    bool jpestora = jp > 23, mariaestora = mp > 23;
    if (jpestora and !mariaestora) {
        cout << 1 << '\n';
        return;
    } else if (mariaestora) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        int comum; cin >> comum;
        jp += min(comum, 10);
        mp += min(comum, 10);
        jpestora = jp > 23;
        mariaestora = mp > 23;
        if (jpestora and !mariaestora) {
            cout << 1 << '\n';
            return;
        } else if (mariaestora) {
            cout << -1 << '\n';
            return;
        }
    }

    int diff = max(1, 23 - mp);
    if (diff > 10) {
        cout << -1 << '\n';
    } else {
        cout << diff << '\n';
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
