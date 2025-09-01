#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a1, a2, a3, a4;

    cin >> a1 >> a2 >> a3 >> a4;
    if (a1 == 0) {
        cout << 1 << '\n';
        return;
    }
    cout << a1 + min(a2, a3) * 2 + min(a1 + 1, abs(a2 - a3) + a4) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}