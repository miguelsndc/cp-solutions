#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 1e6 + 5;
const int mod = 998244353;
const ll inf = 1e18;
using ii = pair<int, int>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int fact[maxn];

void sieve() {
    memset(fact, 0, sizeof fact);
    for (int i = 2; i < maxn; i++) {
        if (fact[i] == 0) {
            fact[i] = i;
            for (int j = 2 * i; j < maxn; j += i) {
                if (fact[j] == 0) fact[j] = i;
            }
        }
    }
}

ll fexp(ll a, ll b) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll modinv(ll a) {
    return fexp(a, mod - 2);
}

void solve() {
    int n;
    cin >> n;
    vc<int> a(n);
    for (int& x : a) cin >> x;

    map<int, vc<int>> pexp;
    for (int x : a) {
        map<int, int> factors;
        while (x > 1) {
            int p = fact[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            factors[p] = cnt;
        }
        for (auto& [p, cnt] : factors) {
            pexp[p].push_back(cnt);
        }
    }

    map<int, ll> pinv;
    vc<vc<ii>> updates(n + 1);
    for (auto& [p, e] : pexp) {
        int kp = e.size();
        sort(e.rbegin(), e.rend());
        pinv[p] = modinv(p);
        for (int i = 0; i < kp - 1; i++) {
            int diff = e[i + 1] - e[i];
            ll factor = fexp(pinv[p], -diff);
            updates[i + 1].emplace_back(p, factor);
        }
        if (kp >= 1) {
            ll factor = fexp(pinv[p], e[kp - 1]);
            updates[kp].emplace_back(p, factor);
        }
    }

    ll prod = 1;
    for (auto& [p, e] : pexp) {
        if (!e.empty()) {
            prod = (prod * fexp(p, e[0])) % mod;
        }
    }
    ll ans = prod;
    for (int i = 1; i < n; i++) {
        for (auto& [p, factor] : updates[i]) {
            prod = (prod * factor) % mod;
        }
        ans = (ans + prod) % mod;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}