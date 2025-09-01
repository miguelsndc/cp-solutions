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

void solve() {
    int n;
    cin >> n;

    vc<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vc<int> pref(n + 1), suf(n + 1);

    for (int i = 0; i < n; i++) {
        pref[i + 1] = __gcd(pref[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, gcd(pref[i], suf[i + 1]));
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}