#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool isvalid(int row, int col, vector<vector<int>> &grid) {
    return (
        row >= 0 && row < grid.size() &&
        col >= 0 && col < grid[0].size() &&
        grid[row][col] > 0
    );
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    vector<int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }
        int max_vol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] != 0) {
                    queue<array<int, 3>> q;
                    q.push({i, j, g[i][j]});
                    g[i][j] = 0;
                    int volume = 0;
                    while(!q.empty()) {
                        auto [ii, jj, val] = q.front();
                        q.pop();
                        volume += val;
                        for(int i = 0; i < 4; i++) {
                            int dii = ii + dirs[i][0];
                            int djj = jj + dirs[i][1];
                            if (isvalid(dii, djj, g)) {
                                q.push({dii, djj, g[dii][djj]});
                                g[dii][djj] = 0;
                            }
                        }
                    }
                    max_vol = max(max_vol, volume);
                }
            }
        }
        cout << max_vol << '\n';
    }
}