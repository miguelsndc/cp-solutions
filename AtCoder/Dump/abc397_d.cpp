#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

void solve() {
    ll n;
    cin >> n;
    // given y = n + x³
    // loop from 1 through 10^6 and find if n + x * x * x is a perfect cube, can do it in log n

    auto cuberoot = [&](ll x) {
        long double l = 1.0, r = x + .0, ans = 1;
        long double eps = 1e-6;
        while (r - l > eps) {
            long double m = l + (r - l) / 2.0;
            if (m * m * m > x) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    };

    for (ll i = 1; i <= (1e6); i++) {
        ll cx = i * i * i;
        ll cy = n + cx;

        long double rooty = cuberoot(cy);
        ll rootfloor = rooty;
        ll rootceil = ceill(rooty);

        if (rootfloor * rootfloor * rootfloor == cy) {
            cout << i << ' ' << rootfloor << '\n';
            return;
        }

        if (rootceil * rootceil * rootceil == cy) {
            cout << i << ' ' << rootceil << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}