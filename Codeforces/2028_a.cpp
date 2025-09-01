#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int x = 0, y = 0, ok = 0;
    for (int i = 0; i < 10000; i++) {
        if (s[i % n] == 'N') y++;
        if (s[i % n] == 'E') x++;
        if (s[i % n] == 'S') y--;
        if (s[i % n] == 'W') x--;
        ok |= (x == a and y == b);
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}