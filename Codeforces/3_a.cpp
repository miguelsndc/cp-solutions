#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    string kpos, tpos;
    cin >> kpos >> tpos;
    int n = 8;
    pair<int, int> src = {
        n - (int)(kpos[1] - '0'),
        (int)(kpos[0] - 'a'),
    };
    pair<int, int> target = {
        n - (int)(tpos[1] - '0'),
        (int)(tpos[0] - 'a'),
    };

    const int inf = 1e9;
    vc dist(n, vc<int>(n, inf));
    auto valid = [&](int i, int j) {
        return i >= 0 and i < n and j >= 0 and j < n;
    };

    typedef tuple<int, int, string> mv;
    vc<mv> dirs = {
        {0, 1, "R"},
        {1, 1, "RD"},
        {1, 0, "D"},
        {0, -1, "L"},
        {1, -1, "LD"},
        {-1, -1, "LU"},
        {-1, 0, "U"},
        {-1, 1, "RU"},
    };

    queue<pair<int, int>> q;
    q.push(src);
    vc<vc<mv>> prev(n, vc<mv>(n));
    mv diff = {69, 69, "420"};
    prev[src.first][src.second] = diff;
    dist[src.first][src.second] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + get<0>(dirs[i]);
            int nc = c + get<1>(dirs[i]);
            if (valid(nr, nc) and dist[nr][nc] > (dist[r][c] + 1)) {
                dist[nr][nc] = dist[r][c] + 1;
                prev[nr][nc] = dirs[i];
                q.push({nr, nc});
            }
        }
    }

    vector<string> path;
    pair<int, int> cur = target;
    while (cur != src) {
        path.push_back({get<2>(prev[cur.first][cur.second])});
        int dx = get<0>(prev[cur.first][cur.second]);
        int dy = get<1>(prev[cur.first][cur.second]);
        cur.first -= dx;
        cur.second -= dy;
    }

    reverse(all(path));

    cout << path.size() << '\n';
    for (string x : path) {
        cout << x << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}