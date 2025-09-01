#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pii pair<int, int>
const int mxn = 1e6;
void solve() {
    ull L, R; cin >> L >> R;
    ull msbL = 63 - __builtin_clzll(L);
    ull msbR = 63 - __builtin_clzll(R);
    int ans = max(__builtin_popcountll(L), __builtin_popcountll(R));
    // cout << msbL << ' ' << msbR << '\n';
    for (int b = msbL; b <= msbR; b++) {
        ull c = (1LL << b) - 1;
        if (c >= L and c <= R) {
            ans = max(ans, __builtin_popcountll(c));
        }
    }
    for (int x = msbR; x >= 0; x--) {
        ull r = R;
        r &= ~(1LL << x);
        r |= (1LL << x) - 1;
        if (r >= L and r <= R) {
            ans = max(ans, __builtin_popcountll(r));
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}