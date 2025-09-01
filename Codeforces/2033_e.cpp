#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    int p[n], vis[n] = {0};
    for (int i = 0; i < n; i++) cin >> p[i], --p[i];
    int ans = 0, len = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            len = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = p[j];
                len++;
            }
            ans += (len - 1) / 2;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}