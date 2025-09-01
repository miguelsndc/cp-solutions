#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    int N; cin >> N;
    vector<pair<int,int>> intervals(N);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        intervals[i] = {x + y, x - y};
    }
    sort(all(intervals));
    int last = -(1 << 30), ans = 0;
    for (int i = 0; i < N; i++) {
        if (last <= intervals[i].second) {
            ans++;
            last = intervals[i].first;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}