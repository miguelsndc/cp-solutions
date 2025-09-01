#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void solve() {
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    
    for (ll x = P; x <= Q; x++) {
        for (ll y = R; y <= S; y++) {
            ll difx = x - A, dify = y - B;
            bool ok = true;
            ok &= llabs(difx) == llabs(dify);
            ll k = difx;
            if ((difx >= 0LL) == (dify >= 0LL)) {
                ok &= (min(1LL - A, 1LL - B) <= k) and (k <= min(N - A, N - B));
            } else {
                ok &= ((min(1LL - A, B - N) <= k) and (k <= min(N - A, B - 1LL)) || (min(1LL - A, B - N) <= -k) and (-k <= min(N - A, B - 1LL)));
            }

            if (ok) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}