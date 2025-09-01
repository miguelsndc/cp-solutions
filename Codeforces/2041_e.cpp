#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    // for (int a = -100; a <= 100; a++) {
    //     for (int b = -100; b <= 100; b++) {
    //     }
    // }
    int v = a * 3 - b;
    int x = (v / 2);
    int y = (v + (v < 0 ? -1 : 1)) / 2;
    x -= 10000;
    y += 10000;

    cout << 3 << '\n';
    cout << x << ' ' << b << ' ' << y << '\n';
    assert(((x + y + b) / 3) == a);
    assert(x <= b and b <= y);
    assert(abs(x) <= 1000000 and abs(y) <= 1000000);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}