#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, m; 
    cin >> n >> m;
    string path; 
    cin >> path;
    vector<vector<i64>> grid(n, vector<i64>(m));
    for (int i = 0 ; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];
    int r = 0, c = 0;
    // quando se anda pra direita ou pra esquerda nunca mais se passa por aquela linha/coluna
    // entao temos q consertá-las e depois partir pra proxima
    for (char ch: path) {
        if (ch == 'D') {
            i64 sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[r][i];
            }
            grid[r][c] = -sum;
            r++;
        } else {
            i64 sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[i][c];
            }
            grid[r][c] = -sum;
            c++;
        }
    }

    // o algoritmo nao chega na ultima celula
    i64 sum = 0;
    for (int i = 0; i < m; i++) {
        sum += grid[n - 1][i];
    }
    grid[n - 1][m - 1] = -sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  cin >> tt;
    while(tt--) {
        solve();
    }
}