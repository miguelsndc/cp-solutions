#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int N; cin >> N;
    int min_x = 1e9, max_x = -1e9, min_y = 1e9, max_y = -1e9;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    cout << min_x << ' ' << min_y << '\n';
    cout << min_x << ' ' << max_y << '\n';
    cout << max_x << ' ' << min_y << '\n';
    cout << max_x << ' ' << max_y << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}