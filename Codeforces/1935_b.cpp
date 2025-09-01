#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rdvec(a, n) \
    for (int i = 0; i < (n); i++) cin >> (a)[i];

void solve() {
    int n;
    cin >> n;
    int a[n];
    rdvec(a, n);

    int pref[n + 1] = {0}, suf[n + 1] = {0};
    int s[n + 1] = {0}, mex = 0;
    for (int i = 0; i < n; i++) {
        s[a[i]] = 1;
        while (s[mex]) mex++;
        pref[i] = mex;
    }
    fill(s, s + n + 1, 0);
    mex = 0;
    for (int i = n - 1; i >= 0; i--) {
        s[a[i]] = 1;
        while (s[mex]) mex++;
        suf[i] = mex;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (pref[i] == suf[i + 1]) {
            ans.push_back({1, i + 1});
            ans.push_back({i + 2, n});
            break;
        }
    }

    if (ans.size()) {
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}