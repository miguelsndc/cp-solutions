#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx -= (sx + sy) % 2;
    tx -= (tx + ty) % 2;
    ll dx = abs(sx - tx);
    ll dy = abs(sy - ty);
    cout << (dy + max(dx, dy)) / 2 << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}