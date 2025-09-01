#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    ll N, A, B; cin >> N >> A >> B;
    if (A == 0) {
        cout << 0 << '\n';
        return;
    }
    ll ans = (N / (A + B)) * A + min(A, N % (A + B));
    cout << ans << '\n';
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}