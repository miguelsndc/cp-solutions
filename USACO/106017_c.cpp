#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
template<class T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T>
struct Frac {
    T p, q;
    Frac() {
        p = 0, q = 1;
    }
    Frac(T x) {
        p = x;
        q = 1;
    }
    Frac(T a, T b) {
        if(b == 0) {
            a = 0;
            b = 1;
        }
        p = a;
        q = b;
        fix();
    }
    Frac<T> operator + (Frac<T> o) const { return Frac(p * o.q + o.p * q, q * o.q); }
    Frac<T> operator - (Frac<T> o) const {return Frac(p * o.q - o.p * q, q * o.q); }
    Frac<T> operator * (Frac<T> o) const { return Frac(p * o.p, q * o.q); }
    Frac<T> operator / (Frac<T> o) const { return Frac(p * o.q, q * o.p); }

    void fix() {
        if(q < 0) {
            q = -q;
            p = -p;
        }
        auto g = gcd(std::max(p, -p), q);
        p /= g;
        q /= g;
    }

    bool operator < (Frac<T> o) const { return ((*this) - o).p < 0; }
    bool operator > (Frac<T> o) const { return ((*this) - o).p > 0; }
};
typedef Frac<ll> rational;
void solve() {
    int q; cin >> q;
    vector<rational> bottles(q);
    rational mult(1);
    rational add(0);
    vector<pair<rational, rational>> history;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            long long x; cin >> x;
            x = (__int128_t)x;
            bottles[i] = rational(x);
        }
        if (t == 2) {
            long long x; cin >> x;
            x = (__int128_t)x;
            add = add + rational(x);
        }
        if (t == 3) {
            long long p, q; cin >> p >> q;
            p = (ll)p;
            q = (ll)q;
            rational f = rational(p, q);
            mult = mult * f;
            add = add * f;
        }
        if (t == 4) {
            int j; cin >> j; --j;
            rational x = bottles[j];
            auto [Mj, Aj] = history[j];
            rational val = x * (mult / Mj) + (add - Aj * (mult / Mj));
            long long ans = (long long) val.p;
            cout << ans << '\n';
        }

        history.push_back({mult, add});
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}