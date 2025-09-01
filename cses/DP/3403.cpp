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
    vector<int> s(n), t(n);
    for (int &x : s) cin >> x;
    for (int &x : t) cin >> x;
    vector f(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i >= 1 and j >= 1) {
        if (s[i - 1] == t[j - 1]) {
            lcs.push_back(t[j - 1]);
            i--, j--;
        } else if (f[i][j - 1] > f[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }
    cout << lcs.size() << '\n';
    reverse(all(lcs));
    for (int x : lcs) {
        cout << x << ' ';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}