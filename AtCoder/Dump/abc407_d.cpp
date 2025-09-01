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
using ull = unsigned long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int h, w;
    cin >> h >> w;
    vector A(h, vector<ull>(w));
    for (auto&& row : A) {
        for (auto&& a : row) {
            cin >> a;
        }
    }
    vector<ull> possible{0};
    const unsigned vertical = (1ULL << w) + 1, horizontal = 3;

    for (ull i = 0, bit = 0; i < h; i++) {
        for (ull j = 0; j < w; j++, bit++) {
            vector<ull> tmp;
            for (const auto b : possible) {
                if (j + 1 < w and !(b & horizontal << bit)) {
                    tmp.emplace_back(b | horizontal << bit);
                }
                if (i + 1 < h and !(b & vertical << bit)) {
                    tmp.emplace_back(b | vertical << bit);
                }
            }
            ranges::move(tmp, back_inserter(possible));
        }
    }

    ull ans = 0;
    for (const auto b : possible) {
        ull now = 0;
        for (ull i = 0, bit = 0; i < h; i++) {
            for (ull j = 0; j < w; j++, bit++) {
                if (1 & ~b >> bit) now ^= A[i][j];
            }
        }
        ans = max(ans, now);
    }

    cout << ans << '\n';
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}