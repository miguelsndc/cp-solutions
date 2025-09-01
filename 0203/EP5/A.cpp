#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 51;
const ll MAXD = 1e9;

ll solve() { 
    ll dist[MAXN][MAXN];
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            dist[i][j] = x;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int r; cin >> r;
    ll cost = 0;
    for (int i = 0; i < r; i++) {
        int a, b; cin >> a >> b;
        cost += dist[a][b];
    }

    return cost;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": " << solve() << '\n';
    }
}