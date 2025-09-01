#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int m; cin >> m;
    ll last = 1, curr = 1;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 1) last *= 2;
        curr += last;
    }
    cout << curr << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}