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

void faz(int n, vc<vc<int>>& g) {
    for (int height = 1; height <= n; ++height) {
        for (int width = 1; width <= n; ++width) {
            for (int i = 0; i <= n - height; ++i) {
                for (int j = 0; j <= n - width; ++j) {
                    for (int x = 0; x < height; ++x) {
                        for (int y = 0; y < width; ++y) {
                            g[i + x][j + y]++;
                        }
                    }
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vc<vc<int>> ans(n, vc<int>(n));

    int x = n / 2;
    int y = n / 2;

    if (n % 2 == 0) x--, y--;

    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};

    int len = 1;
    int dir = 0;
    int steps = 0;
    int val = 0;

    ans[y][x] = val++;

    while (val < n * n) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < len; ++j) {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < n && y >= 0 && y < n)
                    ans[y][x] = val++;
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}