#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve(int cc) {
        int M, N;
        cout << "Case #" << cc << endl;
        cin >> M >> N;
        if (M == 0 && N == 0) return;
        if (cc > 1) cout << endl; // Blank line between cases

        vector<string> grid(M);
        for (int i = 0; i < M; i++) cin >> grid[i];

        int r_s, c_s, r_t, c_t;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'S') r_s = i, c_s = j;
                else if (grid[i][j] == 'T') r_t = i, c_t = j;
            }
        }

        vector<vector<vector<vector<int>>>> dist( M, vector<vector<vector<int>>>(N, vector<vector<int>>(4, vector<int>(5, -1))));
        queue<array<int, 4>> q;

        q.push({r_s, c_s, 0, 0});
        dist[r_s][c_s][0][0] = 0;

        int min_time = -1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c, dir, seg] = q.front();
            q.pop();

            if (r == r_t && c == c_t && seg == 0) {
                if (min_time == -1 || dist[r][c][dir][seg] < min_time) {
                    min_time = dist[r][c][dir][seg];
                }
            }

            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] != '#') {
                int new_seg = (seg - 1 + 5) % 5;
                if (dist[nr][nc][dir][new_seg] == -1) {
                    dist[nr][nc][dir][new_seg] = dist[r][c][dir][seg] + 1;
                    q.push({nr, nc, dir, new_seg});
                }
            }

            int new_dir = (dir - 1 + 4) % 4;
            if (dist[r][c][new_dir][seg] == -1) {
                dist[r][c][new_dir][seg] = dist[r][c][dir][seg] + 1;
                q.push({r, c, new_dir, seg});
            }

            new_dir = (dir + 1) % 4;
            if (dist[r][c][new_dir][seg] == -1) {
                dist[r][c][new_dir][seg] = dist[r][c][dir][seg] + 1;
                q.push({r, c, new_dir, seg});
            }
        }

        if (min_time != -1) {
            cout << "minimum time = " << min_time << " sec" << endl;
        } else {
            cout << "destination not reachable" << endl;
        }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        solve(t);
    }
}
