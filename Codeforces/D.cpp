#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
constexpr int mod = 1e9 + 7, maxn = 2e7 + 5;

bool prime[maxn];
vector<ll> primes, ps;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(rall(a));
    int best = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i - 1];
        if (sum >= ps[i]) {
            best = i;
        }
    }
    cout << (n - best) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;
    for (ll i = 2; i < maxn; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < maxn; j += i) {
                prime[j] = false;
            }
        }
    }

    ps.assign(primes.size() + 1, 0);
    for (int i = 0; i < primes.size(); i++) {
        ps[i + 1] = ps[i] + primes[i];
    }

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}