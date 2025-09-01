#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    for (int k = 0; k < t; k++) {
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'B' and s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}