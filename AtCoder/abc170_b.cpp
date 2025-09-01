#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    int x, y; cin >> x >> y;
    bool ok = false;
    for (int i = 0; i <= x; i++) {
        ok |= ((2 * i + (4 * (x - i))) == y) or (4 * i + (2 * (x- i))) == y;
    }
    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
} 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}