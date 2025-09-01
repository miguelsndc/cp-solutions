#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m, k, T;
    cin >> n >> m >> k >> T;
    vc<ll> a(n);
    for (ll &x : a) cin >> x;

    vc<int> dt(T + 2);
    vc<array<int, 3>> v(k);

    for (int i = 0; i < k; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][0]--;
        dt[v[i][1]]++, dt[v[i][2] + 1]--;
    }

    vc<ii> g[n];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[--a].push_back({--b, w});
        g[b].push_back({a, w});
    }

    auto mssp = [&](int timestamp) -> ll {
        min_heap<pair<ll, ll>> pq;
        const ll inf = numeric_limits<ll>::max();
        vc<ll> dist(n, inf);

        for (int i = 0; i < k; i++) {
            if (timestamp >= v[i][1] and timestamp <= v[i][2]) {
                dist[v[i][0]] = 0;
                pq.push({0, v[i][0]});
            }
        }

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (dist[u] != cost) continue;
            for (auto [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == inf) {
                return -1;
            }
            sum += dist[i] * a[i];
        }
        return sum;
    };
    ll ps = 0, prev = -1, ans = -1;
    for (int i = 1; i <= T; i++) {
        ps += dt[i];
        if (ps != prev) {
            ans = mssp(i);
            prev = ps;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}