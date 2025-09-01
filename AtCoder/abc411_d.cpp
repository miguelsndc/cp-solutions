#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define N 20
vector<int> version_of(N), vt[N];
string s[N];
void dfs(int x) {
    if (vt[x].empty()) return;
    dfs(vt[x][0]);
    cout << s[vt[x][1]];
    return;
}
void solve() {
    int n, q, cnt = 1;
    cin >> n >> q;
    while (q--) {
        string v;
        int t, x;
        cin >> t;
        if (t == 1) {
            cin >> x;
            version_of[x] = version_of[0];
        }
        if (t == 2) {
            cin >> x >> v;
            s[cnt++] = v;
            vt[cnt].push_back(version_of[x]);
            vt[cnt].push_back(cnt - 1);
            version_of[x] = cnt++;
        }
        if (t == 3) {
            cin >> x;
            version_of[0] = version_of[x];
        }
    }
    dfs(version_of[0]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}