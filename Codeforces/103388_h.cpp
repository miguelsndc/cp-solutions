#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, k; cin >> n >> k;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    vector<vector<int>> c(k + 1), idxq(k + 1);
    for (auto [num, col, idx]: v) {
        c[col].push_back(num);
        idxq[col].push_back(idx);
    }
    for (int i = 1; i <= k; i++) {
        sort(c[i].begin(), c[i].end());
    }
    vector<int> ans(n);
    for (int i = 1; i <= k; i++) {
        for(int j = 0; j < c[i].size(); j++) {
            ans[idxq[i][j]] = c[i][j];
        }
    }

    if (is_sorted(ans.begin(), ans.end())) {
        cout << "Y";
    } else {
        cout << "N";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}