#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    ll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = {abs(x), x};
    }
    sort(all(a));

    int same = true, minus = 0, plus = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 1 and a[i].first != a[i - 1].first) same = false;
        if (a[i].second < 0)
            minus++;
        else if (a[i].second > 0)
            plus++;
    }

    if (same and abs(minus - plus) <= 1) {
        cout << "Yes\n";
        return;
    }

    bool flag = true;

    for (int i = 1; i < n - 1; i++) {
        if (a[i].second * a[i].second != a[i + 1].second * a[i - 1].second) flag = false;
    }

    cout << (flag ? "Yes\n" : "No\n");
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}