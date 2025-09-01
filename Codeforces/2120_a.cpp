#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int l1, b1, l2, b2, l3, b3;
    cin >> l1>>  b1 >> l2 >> b2 >> l3 >> b3;

    bool c1 = b1 == b2 and b2 == b3 and (l1 + l2 + l3) == b1;
    bool c2 = l1 == l2 and l2 == l3 and (b1 + b2 + b3) == l1;
    bool c3 = b1 == (b2 + b3) and (l2 == l3) and (b1 == l1 + l2);
    bool c4 = l1 == (l2 + l3) and (b2 == b3) and (l1 == b1 + b2);

    if (c1 or c2 or c3 or c4) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}
