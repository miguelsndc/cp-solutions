#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n, m; cin >> n >> m; 
    int a[n + 1]; 
    vector<int> ps = {0};
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        ps.push_back(s);
    }

    int ans = m;
    for (int d = 1; d <= m; d++) {
        bool ok = true;
        int i = 1;
        while(i <= n) {
            int j = upper_bound(ps.begin(), ps.end(), m - d + ps[i - 1]) - ps.begin();
            if (j == n + 1) break;
            if ((ps[j] - ps[i - 1]) > m) {
                ok = false;
            }
            i = j + 1;
        }

        if (ok) {
            ans = d;
            break;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}
        