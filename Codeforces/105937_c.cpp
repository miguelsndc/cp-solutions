#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    int p = pow(2, n);
    vc<pair<ld, ld>> components(p);
    for (int i = 0; i < p; i++) {
        cin >> components[i].first >> components[i].second;
    }

    vc<ld> ans(300);

    for (int i = 0; i < p; i++) {
        ld prob = (components[i].first * components[i].first + components[i].second * components[i].second);
        ans[i] += prob;
    }

    vc<ld> bla(n);
    for (int mask = 0; mask < p; mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bla[i] += ans[mask];
            }
        }
    }

    cout << setprecision(10) << fixed;
    for (int i = 0; i < n; i++) {
        cout << (1 - bla[i]) << ' ' << bla[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}