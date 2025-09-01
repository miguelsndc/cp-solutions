#include <bits/stdc++.h>
using namespace std;

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

using pii = pair<int, int>;
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
    int h, w;
    cin >> h >> w;
    string s;
    cin >> s;
    int N = s.size();
    vector<int> D(N + 1), R(N + 1);
    for (int i = 0; i < N; i++) D[i + 1] = D[i] + (s[i] == 'D');
    for (int i = 0; i < N; i++) R[i + 1] = R[i] + (s[i] == 'R');
    ll ans = 0;
    for (int n = 0; n < h + w - 1; n++) {
        ll D1 = D[n], D2 = D[N] - D[n];
        ll R1 = R[n], R2 = R[N] - R[n];
        ll mi = max(D1, n - (w - 1 - R2));
        ll ma = min(h - 1 - D2, n - R1);
        ans += ma - mi + 1;
    }
    cout << ans << '\n';
}

int main() {
    fast;
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}