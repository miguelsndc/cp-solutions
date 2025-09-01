#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
void solve() {
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    vector<pair<int, int>> ev;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        ev.push_back({a[i].x, 0});
        ev.push_back({a[i].y, 1});
    }
    sort(ev.begin(), ev.end());
    int op = -1, left = -1;
    vector<pair<int,int>> it;
    for (auto [val, type]: ev) {
        op += (type == 0 ? 1 : -1);
        if (op == 0 and left != -1) {
            it.push_back({left, val});
            left = op = -1;
        } else if (op == 0 and left == -1) {
            left = val;
            op++;
        }
    }
    for (auto[x,y]:it) {
        cout << x << ' ' << y << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}