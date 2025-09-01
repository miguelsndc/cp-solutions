#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int f[n + 1][n + 1];
    memset(f, 0, sizeof f);
    f[0][0] = (a[0][0] != '*');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '*') continue;
            if (i > 0) {
                (f[i][j] += f[i - 1][j]) %= mod;
            } 
            if (j > 0) {
                (f[i][j] += f[i][j - 1]) %= mod;
            }
        }
    } 
    cout << f[n - 1][n - 1] % mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}