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
    ll n;
    cin >> n;

    auto get_msb = [&](ll x) {
        ll msb = 0;
        for (int i = 0; i <= 62; i++) {
            if (x & (1LL << i)) msb = i;
        }
        return msb;
    };

    auto is_palindrome = [&](ll x) {
        ll msb = get_msb(x);

        string s;
        for (int i = 0; i <= msb; i++) {
            if (x & (1LL << i)) {
                s += '1';
            } else {
                s += '0';
            }
        }

        string r = s;
        reverse(all(r));
        return r == s;
    };

    if (is_palindrome(n)) {
        cout << n;
        return;
    }

    ll msb = get_msb(n);
    ll l = msb, r = 0, cur = 0;
    while (l >= r) {
        ll cp = cur;
        cp |= (1LL << l);
        cp |= (1LL << r);
        if (cp <= n) {
            cur = cp;
        } else {
            cur &= ~(1LL << l);
            cur &= ~(1LL << r);
        }
        l--, r++;
    }
    ll bla = 0;
    for (int i = 0; i < msb; i++) {
        bla |= (1LL << i);
    }
    if (bla <= n) {
        cout << max(bla, cur) << '\n';
    } else {
        cout << cur;
    }
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}