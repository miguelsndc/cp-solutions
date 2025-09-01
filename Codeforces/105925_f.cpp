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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    map<ll, ll> dp[5];
    for (int i = 0; i < n; i++) {
        for (int k = 4; k >= 2; k--) {
            for (auto [sum, cnt] : dp[k - 1]) {
                dp[k][sum + a[i]] += cnt;
            }
        }
        dp[1][a[i]] += 1;
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << dp[4][x] << '\n';
    }
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}