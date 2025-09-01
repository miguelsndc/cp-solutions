#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<vc<int>> a(n, vc<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vc<int> ans(n, ((1 << 30) - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans[i] &= a[i][j];
            ans[j] &= a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((ans[i] | ans[j]) != a[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}