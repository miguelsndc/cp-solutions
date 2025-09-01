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

    int cnt = 0;
    int mark[n]{0};
    for (int i = 0; i + 4 < n; i++) {
        string k = s.substr(i, 5);
        if (k == "mapie") {
            cnt++;
            for (int j = 0; j < 5; j++) mark[i + j] = true;
        }
    }

    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == 'p' and s[i + 1] == 'i' and s[i + 2] == 'e' and !mark[i] and !mark[i + 1] and !mark[i + 2])
            cnt++;
        if (s[i] == 'm' and s[i + 1] == 'a' and s[i + 2] == 'p' and !mark[i] and !mark[i + 1] and !mark[i + 2])
            cnt++;
    }
    cout << cnt << '\n';
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}