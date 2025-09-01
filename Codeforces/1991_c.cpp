#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<int> a(n);
    for (int& x : a) cin >> x;
    vc<int> op;
    for (int k = 0; k < 40; k++) {
        int mx = *max_element(all(a));
        int y = ((mx + 1) / 2);
        op.push_back(y);
        for (int& x : a) {
            x = abs(x - y);
        }
    }

    if (*max_element(all(a)) == 0) {
        cout << op.size() << '\n';
        for (int x : op) cout << x << ' ';
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}