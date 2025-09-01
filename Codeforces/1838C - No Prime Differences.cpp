#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e6 + 5;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> rows(n), ans(n);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rows[i].push_back(cnt);
            cnt++;
        }
    }

    int i = 0;
    for (int k = 1; k >= 0; k--) {
        for (int j = k; j < n; j += 2) {
            ans[j] = rows[i];
            i++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}