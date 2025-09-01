#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    ll N; cin >> N;
    ll x0, y0;
    cin >> x0 >> y0;
    ll dist = 1e18;
    pair<int,int> ans = {x0, y0};
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        ll d = (x - x0) * (x - x0) + (y - y0) * (y - y0); 
        if (d < dist) {
            dist = d;
            ans = {x, y};
        } else if (d == dist) {
            dist = d;
            ans = min(ans, {x, y});
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}