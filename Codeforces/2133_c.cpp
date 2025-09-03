#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << " " << n << ' ';
        for (int j = 1; j <= n; j++) {
            cout << j << " \n"[j == n];
        }
        cout.flush();
        int ans; cin >> ans; 
        if (ans == -1) {
            exit(0);
        }
        pq.push({ans, i});
    }
    vector<int> ans{pq.top().second};
    vector<int> seen(n + 1);
    seen[pq.top().first] = true;
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (seen[c]) continue;
        cout << "? " << ans.back() << ' ' << 2 << ' ' << ans.back() << ' ' << u << '\n';
        cout.flush();
        int val; cin >> val;
        if (val == -1) {
            exit(0);
        }
        if (val == 2) {
            seen[c] = true;
            ans.push_back(u);
        }
    }
    cout << "! " << ans.size() << ' ';
    for (int x: ans) cout << x << ' ';
    cout << '\n';
    cout.flush();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}