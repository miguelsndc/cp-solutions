#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inv2 = 500000004;
void solve() {
    ll n; cin >> n;
    ll s = n * (n + 1) / 2;
    ll f[s + 1] = {0}, mod = 1e9 + 7;
    f[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (int y = s; y >= x; y--) {
            (f[y] += f[y - x]) %= mod;
        }
    }
    if (s & 1) {
        cout << 0 << '\n';
    } else {
        cout << (f[s / 2] * inv2) % mod;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}