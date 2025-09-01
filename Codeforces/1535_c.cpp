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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int lst[2][2];
    memset(lst, -1, sizeof lst);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int p = i & 1;
        // nearest character the breaks good string
        // different at odd positions breaks as well as equals on even positions
        // should be different than that
        // if ? just pick the smallest i
        // 0 or ?
        if (s[i] != '1') j = min(j, max(lst[0][p ^ 1], lst[1][p]));
        // 1 or ?
        if (s[i] != '0') j = min(j, max(lst[0][p], lst[1][p ^ 1]));
        // then we should add
        ans += i - j;
        if (s[i] != '?') lst[s[i] - '0'][p] = i;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}