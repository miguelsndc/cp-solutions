#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    bool ok = false;
    for (int i = 0; i + 1 < n; i++) {
        ok |= (abs(a[i] - a[i + 1]) <= 1);
    }
    if (ok) {
        cout << 0 << '\n';
        return;
    } else if (!ok and n <= 2) {
        cout << -1 << '\n';
        return;
    }
    int yes = false;
    for (int i = 0; i + 2 < n; i++) {
        if (a[i + 1] <= a[i] and a[i + 2] >= a[i]
            or a[i + 2] <= a[i] and a[i + 1] >= a[i]
        ) {
            yes = true;
            break;
        }
    }
    for (int i = 2; i < n; i++) {
        if (a[i - 1] <= a[i] and a[i - 2] >= a[i]
            or a[i - 2] <= a[i] and a[i - 1] >= a[i]
        ) {
            yes = true;
            break;
        }
    }

    if (yes) {
        cout << 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}