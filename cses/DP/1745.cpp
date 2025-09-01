#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    int a[n+1]={0};
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ssum = accumulate(a, a+n+1, 0LL);
    int f[ssum+1]={0};
    f[0] = 1;
    for (int x=1; x<=n; x++) {
        for (int sum = ssum; sum >= a[x]; sum--) {
            f[sum] |= f[sum - a[x]];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= ssum; i++) {
        if (f[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}