#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        mp[x] += y;
    }
    auto it = mp.begin();
    int ans = 0;
    while(it != mp.end()) {
        ll x = it->first, y = it->second;
        if (y > 1) mp[x * 2] += (y / 2);
        if (y & 1) ans++;
        it++;
    }
    cout << ans << '\n';
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}