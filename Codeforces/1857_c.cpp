#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m;
    cin >> m;
    int n = m * (m - 1) / 2, b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n);
    for (int i = 0; i < n; i += --m) cout << b[i] << ' ';
    cout << "1000000000" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}