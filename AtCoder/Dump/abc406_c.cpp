#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define sz(x) (x.size())
namespace rg = std::ranges;

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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<pair<char, ll>> v;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] < p[i + 1]) {
            if (v.empty() or v.back().first == '>')
                v.push_back({'<', 1});
            else
                v.back().second++;
        } else {
            if (v.empty() or v.back().first == '<')
                v.push_back({'>', 1});
            else
                v.back().second++;
        }
    }
    int sz = ssize(v);
    ll ans = 0;
    for (int i = 1; i < sz - 1; i++)
        if (v[i].first == '>') ans += v[i - 1].second * v[i + 1].second;
    cout << ans << '\n';
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}