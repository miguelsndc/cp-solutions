#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    set<int> s;
    int mex = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    while(s.count(mex)) mex++;

    if (mex == 0) {
        cout << 0 << '\n';
        cout.flush();
        int y; cin >> y;

        if (y == -1) {
            return;
        } else {
            exit(0);
        }
    } 

    int cnt = 1;
    cout << mex << '\n';
    cout.flush();
    while (cnt < 2 * n + 1) {
        int y; cin >> y;
        if (y == -1) {
            return;
        } else if (y == -2) {
            exit(0);
        }
        cout << y << '\n';
        cout.flush();
        cnt++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}