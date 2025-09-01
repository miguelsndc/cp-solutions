#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m), seen(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int j = 0;
    seen[a[j]] = 1;

    if (a[0] != b[0]) {
        cout << "TIDAK\n";
        return;
    }

    for (int i = 0; i < m; i++) {
        if (seen[b[i]]) continue;
        if (j + 1 < n and b[i] == a[j + 1]) {
            seen[a[++j]] = 1;
        } else {
            cout << "TIDAK\n";
            return;
        }
    }
    cout << "YA\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}