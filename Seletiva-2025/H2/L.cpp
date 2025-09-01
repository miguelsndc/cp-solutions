#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

vector<vi> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
bool is_valid(int i, int j, int rows, int cols, vector<vi> &visited, vector<string>&grid) {
    return (i >= 0 && i < rows && j >= 0 && j <= cols && !visited[i][j] && grid[i][j] == '.');
}

ll explore(int n, int i, int j, int k,  vector<string> &grid, vector<vi> &visited)  {
    if(!is_valid(i, j, grid.size(), grid[0].size(), visited,grid)) {
        return 0;
    }

    if (n == k) {
        return 1;
    }

    ll paths = 0;

    visited[i][j] = true;
    for (auto dir: dirs) {
        int ny = i + dir[0];
        int nx = j + dir[1];
        paths += explore(n + 1, ny, nx, k, grid, visited);
    }
    visited[i][j] = false;

    return paths;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, k; cin >> h >> w >> k;
    vector<string> grid(h); loop(i, 0, h) cin >> grid[i];
    vector<vi> visited(h, vi(w));
    ll count = 0;
    loop(i, 0, h) {
        loop(j, 0, w) {
            if (grid[i][j] == '.') {
                count += explore(0, i, j, k, grid, visited);
            }
        }
    }

    cout << count;
}