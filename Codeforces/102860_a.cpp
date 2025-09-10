#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    int n; cin >> n;
    vector<int> l(n);
    for (int &i: l) cin >> i;
    int S = accumulate(l.begin(), l.end(), 0);
    vector<int> somas(S + 1);
    somas[0] = 1;
    for (int x: l) {
        for (int s = S; s >= x; s--) {
            somas[s] |= somas[s - x];
        }
    }
    ll ans = 0, cnt = 0;
    for (int i = 0; i <= S; i++) {
        if (somas[i]) {
            ans += S - cnt;
            cnt++;
            cout << ans << '\n';
        }
    }
    cout << ans + cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}