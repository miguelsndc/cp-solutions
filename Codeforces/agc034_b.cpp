#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    string S; cin >> S;
    string K;
    for (int i = 0; i + 1 < S.size(); i++) {
        if (S[i] == 'B' and S[i + 1] == 'C') {
            K += 'D';
            i++;
        } else {
            K += S[i];
        }
    }
    ll ans = 0, cur = 0;
    for (char c: K) {
        if (c == 'A') {
            cur++;
        } else if (c == 'D') {
            ans += cur;
        } else {
            cur = 0;
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