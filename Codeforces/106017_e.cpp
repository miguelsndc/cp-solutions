#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<int> d(n + 1), e(n + 1);
    stack<int> s; vector<int> ans;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) cin >> e[i];

    for (int i = n; i >= 1; i--) {
        while(s.size() > 0 and d[s.top()] > d[i]) s.pop();
        if (s.empty() or e[i] > e[s.top()]) {
            ans.push_back(i);
        } 
        s.push(i);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x: ans) {
        cout << x << ' ';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}