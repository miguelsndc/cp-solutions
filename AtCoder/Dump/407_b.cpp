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
    int x, y;
    cin >> x >> y;
    int total_outcomes = 36;
    set<pair<int, int>> c0, c1;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if ((i + j) >= x) c0.insert({i, j});
            if (abs(i - j) >= y) c1.insert({i, j});
        }
    }
    set<pair<int, int>> ans;
    for (auto [x, y] : c0) {
        ans.insert({x, y});
    }
    for (auto [x, y] : c1) {
        ans.insert({x, y});
    }
    double prob = (ans.size() + .0) / 36.0;
    cout << setprecision(20) << fixed << prob << '\n';
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}