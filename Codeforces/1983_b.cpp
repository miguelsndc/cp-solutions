#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string g[2][n];
    for (int i = 0; i < n; i++)
        cin >> g[0][i];
    for (int i = 0; i < n; i++)
        cin >> g[1][i];

    int colsum[m][2] = {0}, rowsum[n][2] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x <= 1; x++) {
                colsum[j][x] += (g[x][i][j] - '0');
                colsum[j][x] %= 3;

                rowsum[i][x] += (g[x][i][j] - '0');
                rowsum[i][x] %= 3;
            }
        }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++)
        ok &= (rowsum[i][0] == rowsum[i][1]);
    for (int j = 0; j < m; j++)
        ok &= (colsum[j][0] == colsum[j][1]);

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}