#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

#define INF 1e18
int main() {
    ll n, m, q, a, b, w;
    cin >> n >> m >> q;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vll> distance(n + 1, vll(n + 1, INF));

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        if (w < distance[a][b]) {
            distance[a][b] = distance[b][a] = w;
        }
    }

    for (int i = 1; i <= n; i++) distance[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for (ll i = 1; i <= q; i++) {
        cin >> a >> b;
        if (distance[a][b] == INF) {
            distance[a][b] = -1;
        } else if (a == b) {
            distance[a][b] = 0;
        }
        cout << distance[a][b] << '\n';
    }

    return 0;
}