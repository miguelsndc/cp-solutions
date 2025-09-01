#include <bits/stdc++.h>
#define array vector
#define read cin
#define str string
#define write cout
#define endl '\n'
using namespace std;

void solve() {
    int n;
    read >> n;
    array<array<int>> m(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            read >> m[i][j];

    array<array<int>> dx = {{
        {0, 1, 0, -1},  // topleft c
        {1, 0, -1, 0},  // topleft cc
        {1, 0, -1, 0},  // topright c
        {0, 1, 0, -1},  // topright cc
        {0, -1, 0, 1},  // bottomright c
        {-1, 0, 1, 0},  // bottomright cc
        {-1, 0, 1, 0},  // bottomleft c
        {0, -1, 0, 1}   // bottomleft cc
    }};

    array<array<int>> dy = {{
        {1, 0, -1, 0},  // topleft c
        {0, 1, 0, -1},  // topleft cc
        {0, -1, 0, 1},  // topright c
        {-1, 0, 1, 0},  // topright cc
        {-1, 0, 1, 0},  // bottomright c
        {0, -1, 0, 1},  // bottomright cc
        {0, 1, 0, -1},  // bottomleft c
        {1, 0, -1, 0}   // bottomleft cc
    }};

    array<pair<int, int>> starts = {{{0, 0},
                                     {0, 0},
                                     {0, n - 1},
                                     {0, n - 1},
                                     {n - 1, n - 1},
                                     {n - 1, n - 1},
                                     {n - 1, 0},
                                     {n - 1, 0}}};

    long long ans = 0;
    for (int dir = 0; dir < 8; ++dir) {
        array<array<bool>> visited(n, vector<bool>(n, false));
        vector<long long> current;
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            current.push_back(m[i][j]);
            visited[i][j] = true;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[dir][d];
                int nj = j + dy[dir][d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj]) {
                    dfs(ni, nj);
                    return;
                }
            }
        };
        dfs(starts[dir].first, starts[dir].second);
        long long cur = 0, best = 0;
        for (long long v : current) {
            cur = max(0LL, cur + v);
            best = max(best, cur);
        }
        ans = max(ans, best);
    }

    write << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), read.tie(nullptr), write.tie(nullptr);
    solve();
    return 0;
}
