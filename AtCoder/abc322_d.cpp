#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
bool move_left(vector<string> &grid) {
    for (int i = 0; i < 4; i++) {
        if (grid[i][0] == '#') return false;
    }
    vector<string> new_grid(4, string(4, '.'));
    for (int i = 0; i < 4; i++)
        for (int j = 1; j < 4; j++)
            if (grid[i][j] == '#')
                new_grid[i][j - 1] = '#';
    grid.swap(new_grid);
    return true;
}

bool move_right(vector<string> &grid) {
    for (int i = 0; i < 4; i++) {
        if (grid[i][3] == '#') return false;
    }
    vector<string> new_grid(4, string(4, '.'));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == '#')
                new_grid[i][j + 1] = '#';
    grid.swap(new_grid);
    return true;
}

bool move_up(vector<string> &grid) {
    for (int j = 0; j < 4; j++) {
        if (grid[0][j] == '#') return false;
    }
    vector<string> new_grid(4, string(4, '.'));
    for (int i = 1; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (grid[i][j] == '#')
                new_grid[i - 1][j] = '#';
    grid.swap(new_grid);
    return true;
}

bool move_down(vector<string> &grid) {
    for (int j = 0; j < 4; j++) {
        if (grid[3][j] == '#') return false;
    }
    vector<string> new_grid(4, string(4, '.'));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (grid[i][j] == '#')
                new_grid[i + 1][j] = '#';
    grid.swap(new_grid);
    return true;
}

void rotate(vector<string> &grid) {
    vector<string> new_grid(4, string(4, '.'));
    for (int j = 0; j < 4; j++)
        for (int i = 3; i >= 0; i--)
            new_grid[j][3 - i] = grid[i][j];
    grid.swap(new_grid);
}

void traverse(vector<string> grid, vector<vector<string>> &positions) {
    while (move_up(grid));
    while (move_left(grid));
    queue<vector<string>> q;
    set<vector<string>> seen;
    q.push(grid);
    seen.insert(grid);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        positions.push_back(cur);

        auto nxt = cur;
        if (move_left(nxt) && !seen.count(nxt)) {
            seen.insert(nxt);
            q.push(nxt);
        }

        nxt = cur;
        if (move_right(nxt) && !seen.count(nxt)) {
            seen.insert(nxt);
            q.push(nxt);
        }

        nxt = cur;
        if (move_up(nxt) && !seen.count(nxt)) {
            seen.insert(nxt);
            q.push(nxt);
        }

        nxt = cur;
        if (move_down(nxt) && !seen.count(nxt)) {
            seen.insert(nxt);
            q.push(nxt);
        }
    }
}

void solve() {
    vector<vector<string>> grids(3, vector<string>(4));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cin >> grids[i][j];

    vector<vector<vector<string>>> all_positions(3);
    for (int g = 0; g < 3; g++) {
        set<vector<string>> seen_rotations;
        for (int r = 0; r < 4; r++) {
            auto tmp = grids[g];
            for (int i = 0; i < r; i++) rotate(tmp);
            if (seen_rotations.count(tmp)) continue;  // avoid duplicate rotations
            seen_rotations.insert(tmp);
            traverse(tmp, all_positions[g]);
        }
    }

    bool ans = false;
    for (auto &a : all_positions[0]) {
        for (auto &b : all_positions[1]) {
            for (auto &c : all_positions[2]) {
                vector result(4, vector<int>(4));
                for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 4; x++) {
                        if (a[y][x] == '#') result[y][x]++;
                        if (b[y][x] == '#') result[y][x]++;
                        if (c[y][x] == '#') result[y][x]++;
                    }

                bool ok = true;
                for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 4; x++)
                        if (result[y][x] != 1)
                            ok = false;

                if (ok) ans = true;
            }
        }
    }

    cout << (ans ? "Yes\n" : "No\n");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}