#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    int xmin = 1e9, xmax = -1e9, ymin = 1e9, ymax = -1e9;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        xmin = min(xmin, x);
        xmax = max(xmax, x);
        ymin = min(ymin, y);
        ymax = max(ymax, y);
    }

    cout << 2 * (xmax - xmin) + 2 * (ymax - ymin) + 8;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}