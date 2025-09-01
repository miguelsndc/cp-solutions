#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m; cin >> n >> m;
    vector<ll> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i], --x[i];
    }
    vector<ll> v(n + 1);

    auto add = [&] (int from, int to, int num) {
        if (from <= to) {
            v[from] += num;
            v[to] -= num;
        } else {
            v[from] += num;
            v[n] -= num;
            v[0] += num;
            v[to] -= num;
        }
    };
    
    auto dist = [&] (int from, int to) {
        if (from <= to) {
            return to - from;
        } else {
            return n - from + to;
        }
    };

    for (int i = 0; i < m - 1; i++) {
        add(x[i], x[i + 1], dist(x[i + 1], x[i]));
        add(x[i + 1], x[i], dist(x[i], x[i + 1]));
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        v[i + 1] += v[i]; 
        ans = min(ans, v[i]);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}