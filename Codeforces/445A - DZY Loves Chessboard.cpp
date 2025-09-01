#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x; 
#define space cout << ' ';
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 2e5 + 5;

int n,m;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool isvalid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
} 

int get_char[] = {'W', 'B'};

void dfs(int y, int x, vector<string> &grid, int c) {
    grid[y][x] = get_char[c];
    fori(4) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isvalid(ny,nx) && grid[ny][nx] == '.') {
            dfs(ny,nx,grid,1 - c);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<string> grid(n);
    fori(n) cin>> grid[i];
    fori(n) {
        forj(m) {
            if (grid[i][j] == '.') {
                dfs(i, j, grid, 0);
            }
        }
    }
    fori(n) {
        forj(m) {
            write(grid[i][j]);
        }
        writeln("");
    }
}