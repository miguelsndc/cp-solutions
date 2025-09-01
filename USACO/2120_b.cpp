#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, s; cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int dx, dy, x, y; cin >> dx >> dy >> x >> y;
        // eventually falls on (0,0) (4,4)
        if (dx == dy) ans += (x == y);
        // at diagonal
        else ans += (x + y == s);
    }
    cout << ans << '\n';
}
int main() {
    int T = 1; cin >> T;
    while(T--) solve();
}