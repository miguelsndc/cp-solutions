#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    auto valid = [&](int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    };

    vector vis(n, vector<bool>(m));
    vector f(n, vector<bool>(m));

    auto go = [&](int x, int y, char c) -> array<int, 2> {
        if (c == 'L') {
            y--;
        } else if (c == 'R') {
            y++;
        } else if (c == 'U') {
            x--;
        } else {
            x++;
        }
        return {x, y};
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '?') vis[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            int x = i, y = j;
            vector<array<int, 2>> a;
            while (valid(x, y) and !vis[x][y]) {
                vis[x][y] = true;
                a.push_back({x, y});
                auto [a, b] = go(x, y, s[x][y]);
                x = a, y = b;
            }
            if (!valid(x, y) || f[x][y]) {
                for (auto [x, y] : a) {
                    f[x][y] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '?') {
                bool ok = false;
                for (auto c : {'L', 'R', 'D', 'U'}) {
                    auto [x, y] = go(i, j, c);
                    if (valid(x, y) and !f[x][y]) {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    f[i][j] = true;
                }
            }
        }
    }

    int ans = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j]) ans--;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}