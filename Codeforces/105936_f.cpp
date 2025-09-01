#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = 998244353;
const int inf = 1e9 + 9;
const int mxn = 1e6 + 5;

ll fact[mxn], inv[mxn];

ll fexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

ll modinv(ll a) {
    return fexp(a, M - 2);
}

ll comb(ll n, ll k) {
    if (k > n || k < 0) return 0;
    return (((fact[n] * inv[k]) % M) * inv[n - k]) % M;
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < mxn; i++)
        fact[i] = (fact[i - 1] * i) % M;
    inv[0] = 1;
    for (int i = 1; i < mxn; i++)
        inv[i] = modinv(fact[i]);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int sr = -1, sc = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'R') {
                sr = i;
                sc = j;
                break;
            }
        }
        if (sr != -1) break;
    }

    vector<vector<int>> dist(n, vector<int>(m, inf));
    queue<pair<int, int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int min_q = inf;
    int max_dist = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (mat[r][c] == 'Q') {
            min_q = min(min_q, dist[r][c]);
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != '#') {
                if (dist[nr][nc] > dist[r][c] + 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<ll> cnt(mxn, 0);
    int total_empty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.' && dist[i][j] < inf) {
                cnt[dist[i][j]]++;
                total_empty++;
                if (dist[i][j] > max_dist) {
                    max_dist = dist[i][j];
                }
            }
        }
    }

    for (int i = max_dist; i >= 0; i--) {
        cnt[i] += cnt[i + 1];
    }

    int d_max = (min_q == inf) ? max_dist : min_q;

    ll ek = comb(total_empty, k);
    ll invek = modinv(ek);

    ll ans = 0;
    for (int d = 1; d < d_max; d++) {
        ll ways_d = comb(cnt[d], k);
        ll ways_d_plus = comb(cnt[d + 1], k);
        ll f = (ways_d - ways_d_plus + M) % M;
        ans = (ans + d * f) % M;
    }
    ll f = comb(cnt[d_max], k);
    ans = (ans + d_max * f) % M;

    ans = ans * invek % M;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}