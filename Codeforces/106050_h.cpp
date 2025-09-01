#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
void solve() {
    ll L, R; cin >> L >> R;
    // menor 10^(x - 1)
    // maior 9* 10^x + 9*10^(x- 1)....
    auto f = [&](ll x) -> ll {
        return (ll)(sqrtl(x));
    };
    vector<ll> pw10(18), nine(18);
    pw10[0] = 1;
    for (int i = 1; i < 18; i++) {
        pw10[i] = 10 * pw10[i - 1];
    }

    cout << f(pw10[R] - 1) - f(pw10[L - 1] - 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}