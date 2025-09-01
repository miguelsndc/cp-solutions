#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n), mark(n);
    for (int & x: a) cin>>x;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
        if (res.size() > 0 and a[i] > res.back()) {
            res.push_back(a[i] % 10);
            res.push_back(a[i] / 10);
        } else {
            res.push_back(a[i]);
        }
    }
    if (is_sorted(res.rbegin(), res.rend())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}