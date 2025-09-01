#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, m; cin >> n >> m;
    m -= n;
    vector<ll> ans, rem;
    for (int i = n - 1; i >= 0; i--) {
        if (m >= i) {
            m -= i;
            // colocar o maior q couber
            ans.push_back(i);
        } else {
            // 1
            rem.push_back(i);
        }
    }
    // < n or > nC2
    if (m != 0) {
        cout << -1 << '\n';
        return;
    }
    ans.insert(ans.end(), rem.begin(), rem.end());
    cout << ans[0] + 1<< '\n';
    for (int i = 0; i + 1< ans.size(); i++) {
        cout << ans[i] + 1<< ' ' << ans[i + 1] + 1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}
