#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    bool ok = false;
    for (int i = 0; i + 2 < n; i++) {
        if (a[i].first == a[i].second and a[i + 1].first == a[i + 1].second and a[i + 2].first == a[i + 2].second) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
