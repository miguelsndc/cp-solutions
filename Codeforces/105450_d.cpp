#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        int g = __gcd(a[i].x, a[i].y);
        a[i].x /= g;
        a[i].y /= g;
    }
    map<pii,int> mp;
    for (auto &p: a) {
        mp[p]++;
    }
    int ans = 0;
    for (auto[_, freq]: mp) ans = max(ans, freq);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}