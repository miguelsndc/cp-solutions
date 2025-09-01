#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int maxn = 2e5 + 10;
const int mod = 998244353;

#define vc vector

ll fact[maxn];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s.push_back('$');

    vector<int> blocks;

    int sz = 1, cur = (int)(s[0] - '0');
    for (int i = 1; i < n + 1; i++) {
        if ((int)(s[i] - '0') == cur) {
            sz++;
        } else {
            blocks.push_back(sz);
            sz = 1;
            cur = 1 - cur;
        }
    }

    ll ans = 1;
    for (int i = 0; i < blocks.size(); i++) {
        ans = (ans * blocks[i]) % mod;
    }
    ans = (ans * fact[(n - blocks.size())]) % mod;
    cout << (n - blocks.size()) << ' ' << ans << '\n';
}

int32_t main() {
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}