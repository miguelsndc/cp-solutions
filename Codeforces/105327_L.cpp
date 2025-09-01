#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    int bitfreq[32] = {0};
    for (int i =0; i < n; i++) {
        int x; cin >> x;
        for (int b = 0; b <= 30; b++) {
            if (x & (1 << b)) {
                bitfreq[b]++;
            }
        }
    }
    int ans[n] = {0};
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int b = 30; b >= 0; b--) {
            if (bitfreq[b] > 0) {
                curr |= (1 << b);
                bitfreq[b]--;
            }
        }
        ans[i] = curr;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}