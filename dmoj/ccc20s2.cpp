#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    const int mxn = 1e6 + 5;
    int n, m;
    cin >> n >> m;
    vector grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];

    vector<vector<int>> div(mxn);
    vector visited(n + 1, vector<bool>(m + 1));
    vector<int> seen(mxn);
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        if (seen[grid[r][c]]) {
            vector<int> &v = div[grid[r][c]];
            for (int x : v) {
                if (x > n or (grid[r][c] / x) > m) continue;
                if (!visited[x][grid[r][c] / x]) {
                    visited[x][grid[r][c] / x] = true;
                    q.push({x, grid[r][c] / x});
                }
            }
        } else {
            for (int i = 1; i * i <= min(n * m, grid[r][c]); i++) {
                if (grid[r][c] % i == 0) {
                    div[grid[r][c]].push_back(i);
                    if (grid[r][c] / i != i) div[grid[r][c]].push_back(grid[r][c] / i);
                }
            }
            seen[grid[r][c]] = true;
            for (int x : div[grid[r][c]]) {
                if (x > n or (grid[r][c] / x) > m) continue;
                if (!visited[x][grid[r][c] / x]) {
                    visited[x][grid[r][c] / x] = true;
                    q.push({x, grid[r][c] / x});
                }
            }
        }
    }
    
    if (visited[n][m]) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}