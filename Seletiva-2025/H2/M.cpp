#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

void solve(int col, int*count, int*right_diagonal,int*left_diagonal,int*row, char board[8][8]) {
    if (col == 8) {
        count[0]++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (board[i][col] == '.' && right_diagonal[i - col + 7] == 0 && left_diagonal[i + col] == 0 && row[i] == 0) {
            right_diagonal[i - col + 7] = 1; 
            left_diagonal[i + col] = 1; 
            row[i] = 1;

            solve(col + 1, count, right_diagonal, left_diagonal, row, board);

            right_diagonal[i - col + 7] = 0; 
            left_diagonal[i + col] = 0; 
            row[i] = 0;
        }
    }
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char board[8][8];
    int right_diagonal[16] = {0};
    int left_diagonal[16] = {0}; 
    int row[8] = {0};
    int count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, &count, right_diagonal, left_diagonal, row, board);

    cout << count;
}