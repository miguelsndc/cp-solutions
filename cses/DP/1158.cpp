#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, x; cin >> n >> x;
    int h[n], s[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];    
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int f[x + 1];
    memset(f,0,sizeof f);
    for (int i = 0; i < n; i++) {
        for (int w = x; w > 0; w--) {
            if (w - h[i] >= 0) {
                f[w] = max(f[w], f[w - h[i]] + s[i]);
            }
        }
    }
    int ans = *max_element(f, f + x + 1);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
