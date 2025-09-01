#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    ll N, h, k;
    cin >> N >> h >> k;
    vector<array<ll, 3>> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    ll x, y;
    cin >> x >> y;

    if (y >= 0) {
        cout << 0 << '\n';
        return;
    }

    const ll inf = 1e18;
    vector<ll> dist(N + 1, inf);
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (a[i][0] == x and a[i][1] == y) {
            dist[i] = 0;
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == 0) {
            break;
        }

        if (a[u][2] and abs(a[u][1]) <= h and dist[0] > dist[u] + 1) {
            dist[0] = dist[u] + 1;
            q.push(0);
        }

        for (int j = 1; j <= N; j++) {
            if (j == u) continue;

            ll dx = a[u][0] - a[j][0];
            ll dy = a[u][1] - a[j][1];
            ll sq = dx * dx + dy * dy;

            if (a[j][2] and sq <= k * k and dist[j] > dist[u] + 1) {
                dist[j] = dist[u] + 1;
                q.push(j);
            }
            if (a[u][2] and sq <= h * h and dist[j] > dist[u] + 1) {
                dist[j] = dist[u] + 1;
                q.push(j);
            }
        }
    }

    if (dist[0] >= inf) {
        cout << -1 << '\n';
    } else {
        cout << dist[0] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}