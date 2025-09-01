#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int dx[8] = {2, 1, -1, -2, -2, -1,  1,  2};

bool isvalid(int row, int col, vector<vector<int>> &grid) {
    return row >= 0 && row < 8 &&
           col >= 0 && col < 8 &&
           grid[row][col] == -1;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        string start, end; cin >> start >> end;
        vector<vector<int>> g(8, vector<int>(8, -1));
        vector<vector<int>> prev(8, vector<int>(8, -1));

        int start_x = start[0] - 'a';
        int start_y = (start[1] - '0') - 1;

        int end_x = end[0] - 'a';
        int end_y = (end[1] - '0') - 1;

        queue<array<int, 2>> q;
        q.push({start_y, start_x});
        g[start_y][start_x] = 1;
        prev[start_y][start_x] = 69;

        int r = start_y, c = start_x;
        while(!q.empty()) {
            auto [y, x] = q.front();
            r = y, c = x;
            q.pop();

            if (r == end_y && c == end_x) {
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nr = r + dy[i];
                int nc = c + dx[i];

                if (isvalid(nr, nc, g) && prev[nr][nc] == -1) {
                    g[nr][nc] = 1;
                    prev[nr][nc] = i;
                    q.push({nr, nc});
                }
            }
        }

        int moves = 0;
        while(prev[r][c] != 69) {
            int nr = dy[prev[r][c]];
            int nc = dx[prev[r][c]];
            r -= nr;
            c -= nc;
            moves++;
        }

        cout << moves << '\n';
    }
}