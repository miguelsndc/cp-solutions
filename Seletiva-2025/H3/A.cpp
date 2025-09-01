#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007

bool isvalid(int row, int col, vector<string> &board) {
    return (row >= 0 && row < board.size() &&
            col >= 0 && col < board[0].size() &&
            board[row][col] == '.'
       );
}

vector<int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int row, int col, vector<string> &board) {
    board[row][col] = '#';
    for (int i = 0; i < 4; i++) {
        int nrow = row + dirs[i][0];
        int ncol = col + dirs[i][1];
        if (isvalid(nrow, ncol, board)) {
            dfs(nrow, ncol, board);
        }
    } 
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++ ) {
            if (board[i][j] == '.') {
                dfs(i, j, board);
                count++;
            }
        }
    }
    cout << count;
}