#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

using ld = long double;

void solve() {
    ll n, d, h;
    cin >> n >> d >> h;
    vc<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ld area = 0, angle = atanl(h / (1.0 * d / 2.0));
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            if (a[i + 1] >= (a[i] + h)) {
                area += 1.0 * d * h / 2.0;
            } else {
                ld h = a[i + 1] - a[i];
                ld x = h / tanl(angle);
                ld b_men = d - 2 * x;
                area += (d + b_men) * h / 2.0;
            }
        } else {
            area += 1.0 * h * d / 2.0;
        }
    }
    cout << setprecision(20) << fixed << area << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}