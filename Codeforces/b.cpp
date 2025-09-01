#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    int n, m, tt = 1;
    int x, y, color, d; char c;
    while (scanf("%d %d", &n, &m), (n + m)) {
        if (tt > 1) printf("\n");

        vector<vector<char>> grid;
        int startx, starty, celx, cely;
        for (int i = 0; i < n; i++) {
            vector<char> row;
            for (int j = 0; j < m; j++) {
                cin >> c;
                row.push_back(c);
                if (c == 'T')  celx = i, cely = j;
                else if (c == 'S') startx = i, starty = j;
                
            }
            grid.push_back(row);
        }

        vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(5, vector<bool>(4))));
        visited[startx][starty][0][0] = true;
        queue<array<int, 4>> q;
        q.push({startx, starty, 0, 0});

        int steps = 0;
        bool done = false;
        while (!q.empty() && !done) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y, color, d] = q.front(); q.pop();

                if (x == celx && y == cely && color == 0) {
                    done = true;
                    break;
                }
                for (int lr : {1, 3}) {
                    int proxd = (d + lr) % 4;
                    if (!visited[x][y][color][proxd])
                        visited[x][y][color][proxd] = true, q.push({x, y, color, proxd});
                }
                int prox_x = x + dirs[d][0], prox_y = y + dirs[d][1], prox_col = (color + 1) % 5;

                if (prox_x < 0 || prox_x >= n || prox_y < 0 || prox_y >= m) continue;
                if (grid[prox_x][prox_y] == '#' || visited[prox_x][prox_y][prox_col][d]) continue;
                
                visited[prox_x][prox_y][prox_col][d] = true;
                q.push({prox_x, prox_y, prox_col, d});
            }
            if (!done) steps++;
        }
        printf("Case #%d\n", tt++);
        if (done)
            printf("minimum time = %d sec\n", steps);
        else
            printf("destination not reachable\n");
    }
    // funciona vjudge desgraça 2 2
}