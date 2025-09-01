#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<long long>
#define INF 1e18

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<vll> d(505, vll(505, INF));

    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int i = 1, a, b, w; i <= m; i++) {
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = min(d[a][b], (ll) w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int y, x; cin >> y >> x;
        if (d[y][x] == INF) d[y][x] = -1;
        cout << d[y][x] << '\n';
    }
    
    return 0;
}