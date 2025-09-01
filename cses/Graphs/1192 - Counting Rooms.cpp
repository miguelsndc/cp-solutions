#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------

int n, m;  //                        R         L      D       U
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, vector<string> &matrix) {
    matrix[i][j] = '#';
    for (vi &dir : directions) {
        int r = i + dir[0];
        int c = j + dir[1];
        if (r < 0 || c < 0 || r >= n || c >= m || matrix[r][c] == '#') continue;
        dfs(r, c, matrix);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                ans++;
                dfs(i, j, matrix);
            }
        }
    }

    cout << ans;
    return 0;
}