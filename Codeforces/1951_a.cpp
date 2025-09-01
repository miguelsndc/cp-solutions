#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = count(all(s), '1');
    if (c & 1) {
        cout << "NO\n";
        return;
    }

    if (c == 2) {
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == '1' and s[i + 1] == '1') {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}