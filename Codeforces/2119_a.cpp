#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        ll a, b, x, y; cin >> a >> b >> x >> y;
        if (a == b) {
            cout << 0 << '\n';
        } else if (a > b) {
            int na = a ^ 1;
            if (na != b) {
                cout << -1 << '\n';
            } else {
                cout << y << '\n';
            }
        } else {
            int cost = 0;
            for (int i = a; i < b; i++) {
                if (i % 2 == 0) {
                    cost += min(x, y);
                } else {
                    cost += x;
                }
            }
            cout << cost << '\n';
        }
    }
}