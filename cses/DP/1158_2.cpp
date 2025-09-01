#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, x;
    cin >> n >> x;
    int f[x + 1], w[n], v[n];
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        for (int z = x; z >= w[i]; z--) {
            f[z] = max(f[z], f[z - w[i]] + v[i]);
        }
    }

    cout << *max_element(f, f + x + 1) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}