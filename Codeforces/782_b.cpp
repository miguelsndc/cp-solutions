#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using ld = long double;

void solve() {
    int n;
    cin >> n;
    vc<ll> f(n), speed(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    for (int j = 0; j < n; j++) cin >> speed[j];

    ld lo = 0, hi = 1e9;
    for (int i = 0; i < 100; i++) {
        ld m = (lo + hi) / 2;

        vc<pair<ld, ld>> it(n);

        for (int i = 0; i < n; i++) {
            it[i] = {f[i] - m * speed[i], f[i] + m * speed[i]};
        }

        sort(all(it));

        ld l = it[0].first, r = it[0].second;

        for (int i = 1; i < n; i++) {
            l = max(l, it[i].first);
            r = min(r, it[i].second);
        }

        if (l > r) {
            lo = m;
        } else {
            hi = m;
        }
    }

    cout << setprecision(10) << fixed << lo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}