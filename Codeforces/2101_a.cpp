#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

array<int, 4> r = {0, 1, 0, -1}, c = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1, -1));
    auto valid = [&](int i, int j) {
        return i >= 1 and i <= n and j >= 1 and j <= n and a[i][j] == -1;
    };

    function<void(int, int, int, int)> dfs = [&](int i, int j, int x, int m) -> void {
        a[i][j] = x;
        if (x == n * n - 1) return;
        int k = (m + 1) % 4;
        if (valid(i + r[k], j + c[k])) {
            dfs(i + r[k], j + c[k], x + 1, k);
        } else {
            dfs(i + r[m], j + c[m], x + 1, m);
        }
    };
    dfs((n + 1) / 2, (n + 1) / 2, 0, 3);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}