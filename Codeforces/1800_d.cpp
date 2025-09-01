#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5 + 5;

const int b = 137;
const int mod1 = 188'888'881;
const int mod2 = 1e9 + 7;

ll pw1[maxn], pw2[maxn];
pair<ll, ll> h[maxn];

#define fi first
#define se second

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        h[i + 1].fi = ((h[i].fi * b) % mod1 + s[i]) % mod1;
        h[i + 1].se = ((h[i].se * b) % mod2 + s[i]) % mod2;
    }

    auto gt = [&](int a, int b) -> pair<ll, ll> {
        ll h1 = (mod1 + h[b + 1].fi - (h[a].fi * pw1[b - a + 1]) % mod1) % mod1;
        ll h2 = (mod2 + h[b + 1].se - (h[a].se * pw2[b - a + 1]) % mod2) % mod2;
        return {h1, h2};
    };
    set<pair<ll, ll>> st;

    for (int i = 1; i < n; i++) {
        ll f1 = 0, f2 = 0, s1 = 0, s2 = 0;
        if (i - 2 >= 0) {
            auto p = gt(0, i - 2);
            f1 = p.fi;
            f2 = p.se;
        }
        if (i + 1 <= n - 1) {
            auto p = gt(i + 1, n - 1);
            s1 = p.fi;
            s2 = p.se;
        }
        ll len2 = (n - 1) - (i + 1) + 1;

        ll nh1 = ((f1 * pw1[len2] % mod1) + s1) % mod1;
        ll nh2 = ((f2 * pw2[len2] % mod2) + s2) % mod2;

        st.insert({nh1, nh2});
    }

    cout << st.size() << '\n';
}

int main() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pw1[i] = (pw1[i - 1] * b) % mod1;
        pw2[i] = (pw2[i - 1] * b) % mod2;
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}