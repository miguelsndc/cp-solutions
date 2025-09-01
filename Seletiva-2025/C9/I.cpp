#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int isvalid(int n, int m, int i, int j) {
    return i >=0 && i < n && j >= 0 && j < m;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        queue<ii> q; 
        rep(i,0,n) {
            rep(j,0,m) {
                cin >> grid[i][j];
                if (grid[i][j] == '1') {
                    q.push({i, j});
                }
            }
        }
        vector<vi> dist(n, vi(m, 0));
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int r = y + dy[i];
                int c = x + dx[i];
                if (isvalid(n, m, r, c) && grid[r][c] == '0') {
                    dist[r][c] = dist[y][x] + 1;
                    grid[r][c] = '1';
                    q.push({r, c});
                }
            }
        }
        rep(i,0,n) {
            rep(j,0,m) {
                cout << dist[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}