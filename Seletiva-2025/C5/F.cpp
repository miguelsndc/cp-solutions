#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

bool isvalid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int,3>>> pq;
    pq.push({maze[0][0], 0, 0});
    vector<vector<int>> dist(n, vector<int>(m, INT32_MAX));
    dist[0][0] = maze[0][0];
    while(!pq.empty()) {
        auto [cost, row, col] = pq.top(); pq.pop();
        if (dist[row][col] != cost) continue;
        for (int i = 0; i < 4; i++) {
            int newrow = row + dy[i];
            int newcol = col + dx[i];
            if (isvalid(newrow, newcol, n, m)) {
                int newdist = dist[row][col] + maze[newrow][newcol];
                if (dist[newrow][newcol] > newdist) {
                    dist[newrow][newcol] = newdist;
                    pq.push({dist[newrow][newcol], newrow, newcol});
                }
            }
        }
    }
    cout << dist[n - 1][m - 1] << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}