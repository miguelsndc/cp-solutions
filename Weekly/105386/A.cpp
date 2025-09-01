#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {	
    int n, m, k; cin >> n >> m >> k;
    vector grid(n, vector<int> (m + 2));
    for (int i = 0; i < n; i++) {
        grid[i][0] = i;
        for (int j = 1; j <= m + 1; j++) {
            cin >> grid[i][j];
        }
    }

    sort(grid.begin(), grid.end(), [&](const auto &a, const auto &b) {
        if (a[1] != b[1]) return a[1] < b[1];
        ll sa = 0, cnta = 0;
        for (int i = 2; i <= m+1; i++) {
            if (a[i] == -1) cnta++;
            else sa += a[i];
        }

        ll sb = 0, cntb = 0;
        for (int i = 2; i <= m+1; i++) {
            if (b[i] == -1) cntb++;
            else sb += b[i];
        }

        if (sa == sb) {
            return cnta < cntb;
        }
        return sa < sb;
    });

    ll mx_prev = -1;
    int prev_si = -1;
    vector<int> pos;

    for (int i = 0; i < n; i++) {
        ll s = 0;
        pos.clear();
        for (int j = 2; j <= m + 1; j++) {
            if (grid[i][j] == -1) pos.push_back(j);
            else s += grid[i][j];
        }

        ll xxxxxx = (mx_prev == -1 ? -1 : mx_prev + (grid[i][1] > prev_si));
        ll maximoqueda = s + 1LL * pos.size() * k;

        if (maximoqueda < xxxxxx) {
            cout << "No\n";
            return;
        }

        ll diff = max(0LL, xxxxxx - s);
        for (int idx : pos) {
            ll val = min(1LL * k, diff);
            grid[i][idx] = val;
            diff -= val;
        }

        for (int idx : pos) {
            if (grid[i][idx] == -1) grid[i][idx] = 0;
        }

        s = 0;
        for (int j = 2; j <= m + 1; j++) {
            s += grid[i][j];
        }
        mx_prev = s;
        prev_si = grid[i][1];
    }

    sort(grid.begin(), grid.end(), [](const auto &a, const auto &b) {
        return a[0] < b[0];
    });

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= m + 1; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << "\n";
    }
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}