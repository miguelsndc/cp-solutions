#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    set<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        b.insert(a[i]);
        b.insert(a[i] + 1);
    }

    int last = 0, res = 0;
    for (auto x : b) {
        int c = cnt[x];
        res += max(c - last, 0);
        last = c;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}