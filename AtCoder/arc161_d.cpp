#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int N, D; cin >> N >> D;
    if (D > (N - 1) / 2) {
        cout << "No\n";
        return;
    }
    vector<pair<int,int>> edges;
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= D; k++) {
            edges.push_back({i, i + k - (i + k > N ? N: 0)});
        }
    }
    cout << "Yes\n";
    for (auto [x, y]: edges) cout << x << ' ' << y << '\n';
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}