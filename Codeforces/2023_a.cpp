#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][2];
        a[i][0] = a[i][1] + a[i][2];
    }
    sort(all(a));

    for (int i = 0; i < n; i++) {
        cout << a[i][1] << ' ' << a[i][2] << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}