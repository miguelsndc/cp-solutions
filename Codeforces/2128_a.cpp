#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        ll n, c; cin >> n >> c;
        vector<ll> a(n), mark(n);
        for (ll &x: a) cin >> x;
        int cnt = n;
        for (int i = 0; i < n; i++) {
            // pegar maior valor <= c
            int mx = -1, mxi = -1;
            for (int j = 0; j < n; j++) {
                if (a[j] <= c and a[j] > mx and !mark[j]) {
                    mxi = j;
                    mx = a[j];
                }
            }

            if (mxi != -1) {
                mark[mxi] = 1;
                cnt--;
            }

            for (int j = 0; j < n; j++) {
                if (!mark[j]) a[j] *= 2;
            }
        }
        cout << cnt << '\n';
    }
}
