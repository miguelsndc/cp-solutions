#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int cnt = 0;
    int a, x; cin >> a >> x;
    // 2 * 3 * 5
    bool ok = true;
    int k = a;
    for (ll i = 2; i * i <= k; i++) {
        while(a % i == 0) {
            if (i > x) ok = false;
            a /= i;
            cnt++;
        }
    }
    ok &= (a <= x);
    cnt += (a > 1);
    if (ok) {
        cout << cnt << '\n';
    } else {
        cout << "Que es Obo?";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}