#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> pre(n), suf(n);
        for (int i = 0; i < n; i++) {
            pre[i] = a[i] + i;
            suf[i] = a[i] - i;
        }
        for (int i = 1; i < n; i++) pre[i] = max(pre[i], pre[i - 1]);
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i], suf[i + 1]);
        int ans = 0;
        for (int i = 1; i + 1 < n; i++) {
            ans = max(ans, pre[i - 1] + a[i] + suf[i + 1]);
        }
        cout << ans << '\n';
    }
}
