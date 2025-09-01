#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

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

const int maxp = 1e7;

vector<ll> primes, is_prime(maxp + 5, 1);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= maxp; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= maxp; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    sieve();
    ll n;
    cin >> n;
    vector<ll> div;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) div.push_back(n / i);
        }
    }

    if (div.size() == 0) {
        cout << 1 << '\n';
        cout << 0;
        return;
    }

    for (int i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0 and binary_search(all(primes), n / primes[i])) {
            cout << 2 << '\n';
            return;
        }
        if (primes[i] > n) break;
    }

    sort(all(primes));
    for (ll d : div) {
        for (int i = 0; i < primes.size(); i++) {
            if (d % primes[i] == 0 and binary_search(all(primes), d / primes[i])) {
                cout << 1 << '\n';
                cout << d;
                return;
            }
            if (primes[i] > d) break;
        }
    }
    cout << 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}