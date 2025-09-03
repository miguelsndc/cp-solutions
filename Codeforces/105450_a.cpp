#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    int m = n - k;
    if (m == 1) {
        cout << 0 << '\n';
        return;
    }
    int ans = 1e9;
    for (int i = 0; i + m - 1 < n; i++) {
        ans = min(ans, a[i + m - 1] - a[i]);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}