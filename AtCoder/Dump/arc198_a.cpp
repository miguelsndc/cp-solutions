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
    if (n == 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }
    cout << n / 2 << '\n';
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}