#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n, m;
    cin >> n >> m;
    vc<string> in(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    vc<vc<int>> g(n, vc<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = (in[i][j] == 'B');
        }
    }

    /*
        1 - bipartite check
        2 - xadrez se n impar
        3 - pontas se n >= 3 e m >= 3
        4 - vazio
        5 - n tem como
    */
    // 1
    vc<vc<int>> vis(n, vc<int>(m, 0));
    auto check_black_bipartite = [&](vc<vc<int>> &grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;

                if ((i - 1) >= 0 and grid[i - 1][j] == grid[i][j]) return false;
                if ((i + 1) < n and grid[i + 1][j] == grid[i][j]) return false;
                if ((j - 1) >= 0 and grid[i][j - 1] == grid[i][j]) return false;
                if ((j + 1) < m and grid[i][j + 1] == grid[i][j]) return false;
            }
        }
        return true;
    };

    // 1
    if (!check_black_bipartite(g)) {
        cout << "No\n";
        return;
    }

    auto bruta_linha = [&](vc<vc<int>> grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[n - i - 1][j] == 0) {
                    grid[n - i - 1][j] = grid[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[n - i - 1][j] != grid[i][j]) {
                    return false;
                }
            }
        }

        return check_black_bipartite(grid);
    };
    auto bruta_coluna = [&](vc<vc<int>> grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][m - j - 1] == 0) {
                    grid[i][m - j - 1] = grid[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][m - j - 1] != grid[i][j]) {
                    return false;
                }
            }
        }

        return check_black_bipartite(grid);
    };
    bool r = bruta_linha(g);
    bool s = bruta_coluna(g);
    if (r or s) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}