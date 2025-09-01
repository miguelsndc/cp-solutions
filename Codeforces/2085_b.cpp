#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = count(a, a + n, 0);
    if (cnt == 0) {
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
        return;
    }

    vector<pair<int, int>> op;

    int first = 1e9, last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            first = min(i, first);
            last = max(last, i);
        }
    }

    if (first == 0 and last == n - 1) {
        op.push_back({1, 2});
        n--;
        op.push_back({2, n});
        op.push_back({1, 2});
    } else {
        if (first == 0) {
            op.push_back({1, n - 1});
        } else {
            op.push_back({2, n});
        }
        op.push_back({1, 2});
    }

    cout << op.size() << '\n';
    for (auto [x, y] : op) {
        cout << x << ' ' << y << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}