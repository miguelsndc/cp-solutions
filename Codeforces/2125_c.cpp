#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        ll l, r; cin >> l >> r;

        auto f = [&](ll n) -> ll{
            vector<int> p = {2, 3, 5, 7};
            ll cnt = 0;
            for (int mask = 0; mask < (1 << 4); mask++) {
                int bits = __builtin_popcount(mask);

                ll prod = 1;
                for (int i = 0; i < 4; i++) {
                    if (mask & (1 << i)) {
                        prod *= p[i];
                    }
                }

                if (bits % 2 == 1) {
                    cnt -= n / prod;
                } else {
                    cnt += n / prod;
                }
            }

            return cnt;
        };

        cout << f(r) - f(l - 1) << '\n';
    }
}