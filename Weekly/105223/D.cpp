#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

const int maxp = 40000;
vector<int> primes;
int is_prime[maxp];

void sieve() {
    fill(is_prime, is_prime + maxp, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < maxp; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < maxp; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> factors;
    for (int p : primes) {
        if (p * p > n) break;
        int power = 0;
        while (n % p == 0) {
            n /= p;
            power++;
        }
        int e = power % 3;
        if (e != 0) {
            factors.push_back({p, power % 3});
        }
    }
    if (n > 1) {  // should be a big prime
        factors.push_back({n, 1});
    }
    sort(all(factors));
    return factors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<vector<pair<int, int>>, int> mp;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> fac = factor(a[i]);
        cnt += mp[fac];
        mp[fac]++;
    }
    cout << cnt << '\n';
}

int main() {
    sieve();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}