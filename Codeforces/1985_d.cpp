#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int mxrow = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        int cur = count(grid[i].begin(), grid[i].end(), '#');
        if (cur > mx) {
            mxrow = i; mx = cur;
        }
    }
    int mxcol = 0, mxc = 0;
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '#') cnt++;
        }
        if (cnt > mxc) {
            mxcol = j; mxc = cnt;
        }
    }

    cout << mxrow + 1 << ' ' << mxcol + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}