#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[n];
    fill(a, a + n, 1);
    --x, --y;
    int e = -1;
    for (int i = x + 1; i < n; i++) {
        a[i] = e;
        e *= -1;
    }
    e = -1;
    for (int i = y - 1; i >= 0; i--) {
        a[i] = e;
        e *= -1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}