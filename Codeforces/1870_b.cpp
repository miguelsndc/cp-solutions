#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n, m;
    cin >> n >> m;
    vc<int> a(n), b(m);
    int cxor = 0;
    for (int &x : a) {
        cin >> x;
        cxor ^= x;
    }
    for (int &x : b) cin >> x;
    /*
        olhar cada bit b de b
    */
    vc<int> on(30);
    for (int i = 0; i < 30; i++) {
        for (int x : b) {
            if (x & (1 << i)) {
                on[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < 30; i++) {
        for (int &x : a) {
            if (on[i]) {
                x |= (1 << i);
            }
        }
    }

    int newxor = 0;
    for (int x : a) {
        newxor ^= x;
    }

    auto [mn, mx] = minmax(newxor, cxor);
    cout << mn << ' ' << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}