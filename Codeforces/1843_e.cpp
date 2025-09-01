#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, -1), c(n);
    vector<pair<int, int>> segs(m);
    for (int i = 0; i < m; i++) {
        cin >> segs[i].first >> segs[i].second;
        segs[i].first--;
        segs[i].second--;
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i], --queries[i];

    int l = 0, r = q - 1, ans = -1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        vector<int> ps(n + 1), x(n);
        for (int i = 0; i <= m; i++) {
            x[queries[i]]++;
        }
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + x[i];
        int ok = false;
        for (auto [l, r]: segs) {
            if ((ps[r + 1] - ps[l]) > ((r - l + 1) / 2)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << (ans == -1 ? ans : ans + 1) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}