#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

string s = "snuke";

int next(int i) {
    return (i + 1) % 5;
}

bool isvalid(int row, int col, vector<string> &maze, int i) {
    return (
        row >= 0 && row < maze.size() &&
        col >= 0 && col < maze[0].size() &&
        maze[row][col] == s[i]
    );
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> letters(128, -1);

    for (int i = 0; i < s.size(); i++) {
        letters[(int) s[i]] = i;
    }

    vector<int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int h, w; cin >> h >> w;
    vector<string> maze(h);
    for (int i = 0; i < h; i++) cin >> maze[i];
    
    vector<vector<bool>> visited(h, vector<bool>(w));

    int idx = letters[maze[0][0]];
    int idx_end = letters[maze[h - 1][w - 1]];

    if (idx == -1 || idx_end == -1) {
        cout << "No";
        return 0;
    }

    queue<array<int, 3>> q;
    visited[0][0] = true;
    q.push({0, 0, idx});
    bool can = false;
    while(!q.empty()) {
        auto [y, x, id] = q.front();
        q.pop();

        if (y == h - 1 && x == w - 1) {
            can = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dirs[i][0];
            int nx = x + dirs[i][1];
            int didx = next(id); 

            if (isvalid(ny, nx, maze, didx)) {
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx, didx});
                }
            }
        }
    }
    if (can) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}