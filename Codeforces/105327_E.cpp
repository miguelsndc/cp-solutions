#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector g(n, vector<int>(n));
    for (int i = 0 ; i < n; i++) for (int j = 0; j < n; j++) cin >> g[i][j];

    vector<int> col;
    for (int j =0; j < n; j++) col.push_back(g[j][0]);

    bool linhacresc = is_sorted(g[0].begin(), g[0].end());
    bool colcresc = is_sorted(col.begin(), col.end());

    if (linhacresc and colcresc) {
        cout << 0 << '\n';
    } else if (linhacresc and !colcresc) {
        cout << 3 << '\n';
    } else if (!linhacresc and !colcresc) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}