#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return;
    } else if (n & 1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans(n);

    for (int i = n, j = 0; i >= 2, j < n; i -= 2, j += 2) {
        ans[j] = i;
    }
    for (int i = 1, j = 1; i < n, j < n; i += 2, j += 2) {
        ans[j] = i;
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}