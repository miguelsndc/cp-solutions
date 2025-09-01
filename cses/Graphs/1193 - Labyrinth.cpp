#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// -----------

// loop until find A
// from A perform bfs until B is found
// if somehow stuck, path can't be found

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<char> directions_char = {'D', 'U', 'L', 'R'};
    vector<vector<int>> previous(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'A') {
                queue<ii> q;
                q.push(make_pair(i, j));
                previous[i][j] = -2;
                int row, col;
                while (!q.empty()) {
                    row = q.front().first, col = q.front().second;
                    q.pop();
                    if (matrix[row][col] == 'B') {
                        break;
                    }
                    for (int k = 0; k < 4; k++) {
                        int r = row + directions[k][0];
                        int c = col + directions[k][1];
                        if (r < 0 || c < 0 || r >= n || c >= m || matrix[r][c] == '#' || previous[r][c] != -1) continue;
                        q.push(make_pair(r, c));
                        previous[r][c] = k;
                    }
                }

                if (matrix[row][col] != 'B') {
                    cout << "NO";
                    return 0;
                }
                string path;
                while (previous[row][col] != -2) {
                    int dir = previous[row][col];
                    path += directions_char[dir];
                    row -= directions[dir][0];
                    col -= directions[dir][1];
                }
                reverse(path.begin(), path.end());
                cout << "YES\n";
                cout << path.size() << '\n';
                cout << path;
            }
        }
    }

    return 0;
}