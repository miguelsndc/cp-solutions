#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

int f(string& a, string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        cnt += (a[i] != b[i]);
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = f(s, t);
    reverse(all(t));
    int cnt_rev = f(s, t);
    if (cnt == 0) {
        cout << 0 << '\n';
        return;
    }

    if (cnt_rev == 0) {
        cout << 2 << '\n';
        return;
    }

    int x = 2 * cnt - cnt % 2;
    int y = 2 * cnt_rev - (1 - cnt_rev % 2);
    cout << min(x, y) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}