#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0, sum = 0;
    for (auto [v, cnt] : mp) {
        if (cnt >= 3)
            ans += cnt * (cnt - 1) * (cnt - 2) / 6;
        if (cnt >= 2)
            ans += cnt * (cnt - 1) / 2 * sum;
        sum += cnt;
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