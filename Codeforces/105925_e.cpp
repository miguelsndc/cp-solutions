#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define fi first
#define se second
#define sz(x) (x.size())

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

void solve() {
    ll y, k;
    cin >> y >> k;
    vector<ll> div;

    for (ll i = 1; i * i <= y; i++) {
        if (y % i == 0) {
            div.push_back(i);
            if (y / i != i) div.push_back(y / i);
        }
    }

    sort(all(div));

    ll x = 1;

    /*
        ele continua andando gcd(x, y) ate que pare no proximo divisor de y,
        entao o step aumenta pra gcd(div, y)
        preciso achar os divisores que aumentam o tamanho dos passos em ordem
        e dar min(k, step) passos


        da pra chegar nisso observando que a cada vez que ele pisa num
        divisor o passo estende, entao so preciso achar qual o proximo divisor
        que ele vai pisar e calcular quantos passos eu demoro pra chegar la
        se der pra chegar blz se nao eu so ando o max possivel
    */

    for (int i = 0; i < sz(div); i++) {
        if (k == 0) break;
        if (div[i] > x and div[i] % x == 0) {
            ll step = (div[i] / x) - 1;
            if (k >= step) {
                k -= step;
                x = div[i];
            } else {
                x += (x * k);
                k = 0;
            }
        }
    }
    if (k > 0) {
        x += (x * k);
    }

    cout << x << '\n';
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}