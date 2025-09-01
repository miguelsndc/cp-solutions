#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N;
    cin >> N;
    ll h[2][N + 1], f[N + 1][2];
    for (int i = 1; i <= N; i++) cin >> h[0][i];
    for (int i = 1; i <= N; i++) cin >> h[1][i];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= N; i++)
        for (int k = 0; k <= 1; k++)
            f[i][k] = max(f[i - 1][k], f[i - 1][k ^ 1] + h[k][i]);
    cout << max({f[N][0], f[N][1]}) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> tt;
    while (T--) solve();
}