#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<array<int,4>> v(n);
        for (int i = 0; i < n; i++) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            v[i] = {a,b,c,d};
        }
        ll cost = 0;
        for (auto[a,b,c,d]: v) {
            ll d1 = a - c;
            ll d2 = b - d;
            if (d1 >= 0 and d2 >= 0) {
                a -= d1;
                cost += d1 + (d2 > 0 ? a: 0) + d2;
            } else if (d1 >= 0) {
                cost += d1;
            } else if (d2 >= 0) {
                cost += (d2 > 0 ? a : 0);
                cost += d2;
            }
        }
        cout << cost << '\n';
    }
}