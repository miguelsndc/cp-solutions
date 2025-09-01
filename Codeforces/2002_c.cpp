#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define x first
#define y second
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) cin >> c[i].x >> c[i].y;
    long long srcx, srcy, destx, desty;
    cin >> srcx >> srcy >> destx >> desty;
    long long dist = (destx - srcx) * (destx - srcx) + (desty - srcy) * (desty - srcy);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        long long d = (destx - c[i].x) * (destx - c[i].x) + (desty - c[i].y) * (desty - c[i].y);
        if (d <= dist) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
