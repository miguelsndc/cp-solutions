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
    for (int &x : a) cin >> x;

    vc<int> b = a;
    sort(all(b));
    b.resize(unique(all(b)) - begin(b));
    int cnt = count(all(b), 1);
    if (cnt == 1 and b.size() != 1) {
        cout << -1 << '\n';
        return;
    } else if (b.size() == 1) {
        cout << 0 << '\n';
        return;
    }

    vc<pair<int, int>> ops;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) continue;
            while (1) {
                int mxpos, mnpos;
                auto [mn, mx] = minmax(a[i], a[j]);
                if (a[i] > a[j]) {
                    mxpos = i, mnpos = j;
                } else {
                    mxpos = j, mnpos = i;
                }
                int res = mx;

                if (ceil(1.0 * mx / mn) <= 1) {
                    break;
                }
                while (1) {
                    int t = ceil(1.0 * res / mn);
                    if (t > 1 and t < res) {
                        res = t;
                        ops.push_back({mxpos, mnpos});
                    } else {
                        break;
                    }
                }

                a[mxpos] = res;
            }
        }
    }

    assert(ops.size() <= 30 * n);
    cout << ops.size() << '\n';
    for (auto [x, y] : ops) {
        cout << x + 1 << ' ' << y + 1 << '\n';
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