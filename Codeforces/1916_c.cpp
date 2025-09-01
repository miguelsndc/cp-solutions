#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    int cnt_odd = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) cnt_odd++;
        sum += x;
        ll v = (cnt_odd / 3 + (cnt_odd % 3 == 1));
        if (i == 0 and cnt_odd == 1) {
            cout << sum << ' ';
        } else {
            cout << sum - v << ' ';
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}