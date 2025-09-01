#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (mp.count(a[i] - i)) {
            ans += mp[a[i] - i];
        }
        mp[a[i] - i]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}