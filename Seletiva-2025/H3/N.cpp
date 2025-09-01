#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

bool isvalid(int row, int col, vector<string> &grid) {
    return (
        row >= 0 && row < grid.size() &&
        col >= 0 && col < grid[0].size() 
    );
}

vector<int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d; cin >> n >> m >> d;
    vector<string> grid(n);
    array<int, 2> start, finish;
    queue<array<int, 2>> monsters;
    vector<vector<int>> monsters_dist(n, vector<int>(m, INF));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') start = {i, j};
            else if (grid[i][j] == 'F') finish = {i, j};
            else if (grid[i][j] == 'M') { 
                monsters_dist[i][j] = 0;
                monsters.push({i, j}); 
            };
        }
    }

    while(!monsters.empty()) {
        auto [row, col] = monsters.front();
        monsters.pop();
        for (int i = 0; i < 4; i++) {
            int dy = row + dirs[i][0];
            int dx = col + dirs[i][1];
            if (isvalid(dy, dx, grid) && monsters_dist[dy][dx] == INF) {
                monsters_dist[dy][dx] = monsters_dist[row][col] + 1;
                monsters.push({dy, dx});
            }
        }
    }

    auto [finish_y, finish_x] = finish;
    auto [start_y, start_x] = start;

    if (monsters_dist[start_y][start_x] <= d || monsters_dist[finish_y][finish_x] <= d) {
        cout << -1;
        return 0;
    }

    queue<array<int, 2>> player;
    vector<vector<int>> player_dist(n, vector<int>(m, -1));
    player_dist[start_y][start_x] = 0;
    player.push(start);

    while(!player.empty()) {
        auto [row, col] = player.front();
        player.pop();
        if (row == finish_y && col == finish_x) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int dy = row + dirs[i][0];
            int dx = col + dirs[i][1];
            if (isvalid(dy, dx, grid) && monsters_dist[dy][dx] > d && player_dist[dy][dx] == -1) {
                player_dist[dy][dx] = player_dist[row][col] + 1;
                player.push({dy,dx});
            }
        }
    }
    cout << player_dist[finish_y][finish_x];
}
