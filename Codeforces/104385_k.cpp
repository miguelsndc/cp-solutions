#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), diff(n - 1);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i] - a[i + 1];
    }
    sort(all(diff));
    vector<ll> ps(n);
    for (int i = 0; i < n - 1; i++) ps[i + 1] = ps[i] + diff[i];
    int m;
    cin >> m;
    while (m--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            cout << ps[n - x] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}