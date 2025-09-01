#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n), h(n);
    for (int i =0; i < n; i++) {
        cin >>a[i];
    }
    for (int i =0; i < n; i++) {
        cin >>h[i];
    }

    int l = 0; ll sum = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        if (r > 0 and h[r - 1] % h[r] != 0) {
            l = r; sum = 0;
        }
        sum += a[r];
        while(sum > k) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, 1LL * r - l + 1);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}