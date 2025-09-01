#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

const int mod = 998244353;

ll fexp(ll a, ll b, ll MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vc<int> v(n);
    for (int& x : v) cin >> x;
    vc<ll> dp(4, 0);
    dp[0] = 1;
    for (int c : v) {
        if (c == 2) dp[2] = (dp[2] + dp[2]) % mod;
        dp[c] = (dp[c] + dp[c - 1]) % mod;
    }
    cout << dp[3] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}