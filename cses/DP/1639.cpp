#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1), curr(m + 1);
    for (int i = 0; i <= m; i++) prev[i] = i;

    for (int i = 1; i <= n; i++) {
        curr[0] = i;
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = min({curr[j - 1], prev[j], prev[j - 1]}) + 1;
            }
        }
        prev = curr;
    }

    cout << prev[m] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}