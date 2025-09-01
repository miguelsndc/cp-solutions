#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
// gcd(a,b) * lcm(a,b) = a * b
// lcm = a * b / gcd(a,b)
__int128_t mmc(__int128_t a, __int128_t b) {
    return (a / __gcd(a, b)) * b;
}
void solve() {
    int N;
    cin >> N;
    vector<ll> maior_gcd(N);
    for (int i = 0; i < N; i++) {
        int sz;
        cin >> sz;
        vector<int> pre(sz), suf(sz), A(sz);
        for (int &j : A) cin >> j;
        pre[0] = A[0];
        suf[sz - 1] = A[sz - 1];
        for (int j = 1; j < sz; j++) pre[j] = __gcd(pre[j - 1], A[j]);
        for (int j = sz - 2; j >= 0; j--) suf[j] = __gcd(suf[j + 1], A[j]);
        int mx = pre[sz - 1];
        for (int j = 0; j < sz; j++) {
            int g = 0;
            g = __gcd(g, pre[j - 1]);
            if (j > 0) {
            }
            if (j + 1 < sz) {
                g = __gcd(g, suf[j + 1]);
            }
            mx = max(mx, g);
        }
        maior_gcd[i] = mx;
        // cout << mx << '\n';
    }

    vector<__int128_t> pre(N), suf(N);
    pre[0] = maior_gcd[0];
    suf[N - 1] = maior_gcd[N - 1];
    for (int j = 1; j < N; j++) pre[j] = mmc(pre[j - 1], maior_gcd[j]);
    for (int j = N - 2; j >= 0; j--) suf[j] = mmc(suf[j + 1], maior_gcd[j]);

    if (N == 1) {
        cout << maior_gcd[0] << '\n';
        return;
    }

    __int128_t ans = min((__int128_t)1e18 + 1, pre[N - 1]);
    for (int j = 0; j < N; j++) {
        __int128_t g = 1;
        if (j > 0) {
            g = mmc(g, pre[j - 1]);
        }
        if (j + 1 < N) {
            g = mmc(g, suf[j + 1]);
        }
        ans = min(ans, g);
    }
    cout << (ll)ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}