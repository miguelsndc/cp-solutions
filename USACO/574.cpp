#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ifstream fin("feast.in");
    ofstream fout("feast.out");
    ll t, a, b; fin >> t >> a >> b;
    int f[t + 1][2];
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    f[0][1] = 1;
    for (int i = 0; i <= t; i++) {
        if (i + a <= t) f[i + a][0] |= f[i][0];
        if (i + b <= t) f[i + b][0] |= f[i][0];
        f[i/2][1] |= f[i][0];
    }
    for (int i = 0; i <= t; i++) {
        if (i + a <= t) f[i + a][1] |= f[i][1];
        if (i + b <= t) f[i + b][1] |= f[i][1];
    }

    int ans = 1;
    for (int i = 0; i <= t; i++) {
        if (f[i][0] or f[i][1]) ans = i;
    }
    fout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}