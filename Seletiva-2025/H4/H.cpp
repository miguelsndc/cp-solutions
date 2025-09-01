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
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

int n, m, min_r, max_r, min_c, max_c, sz, ans; vector<int> row, col, free_row, free_col; 
vector<vector<bool>> visited; vector<vector<char>> mat;

void dfs(int i, int j) {
    if (i <= 0 || i > n || j <= 0 || j > m || visited[i][j] || mat[i][j] == '.') return;
    visited[i][j] = true;
     sz++;
    min_r = min(min_r, i);
    max_r = max(max_r, i);
    min_c = min(min_c, j);
    max_c = max(max_c, j);
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

void solve() {
    cin >> n >> m;
    row.assign(n + 5, 0);
    col.assign(m + 5, 0);
    free_row.assign(n + 5, 0);
    free_col.assign(m + 5, 0);
    visited.assign(n + 5, vector<bool>(m + 5, false));
    mat.assign(n + 5, vector<char>(m + 5, ' '));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> mat[i][j];
            if (mat[i][j] == '.'){
                free_row[i]++;
                free_col[j]++;
            }
        }
    }

     for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (visited[i][j] or mat[i][j] == '.')
                continue;

            sz = 0;
            min_r = min_c = 1e9;
            max_r = max_c = -1e9;

            dfs(i, j);
            min_r = max(min_r - 1, 1);
            max_r = min(max_r + 1, n);
            min_c = max(min_c - 1, 1);
            max_c = min(max_c + 1, m);
            row[min_r] += sz;
            row[max_r + 1] -= sz;
            col[min_c] += sz;
            col[max_c + 1] -= sz;
        }
    }

    ans = 0;

    for (int i = 1; i <= n; i++){
        row[i] += row[i - 1];
        ans = max(ans, free_row[i] + row[i]);
    }
    for (int i = 1; i <= m; i++){
        col[i] += col[i - 1];
        ans = max(ans, free_col[i] + col[i]);
    }

    cout << ans << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
}