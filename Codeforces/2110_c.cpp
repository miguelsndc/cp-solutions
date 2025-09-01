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
    vc<int> d(n);
    for (int &x : d) cin >> x;
    vc<int> l(n + 1), r(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        l[i] = max(l[i], l[i - 1] + (d[i - 1] == 1 ? 1 : 0));
        r[i] = min(r[i], r[i - 1] + (d[i - 1] == 0 ? 0 : 1));
        if (l[i] > r[i]) {
            ok = false;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    int x = l[n];
    for (int i = n - 1; i >= 0; i--) {
        if (d[i] == -1) {
            int nx = max(x - 1, l[i]);
            d[i] = x - nx;
        }
        x -= d[i];
    }

    for (int x : d) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}