#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

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
    vector<vi> ans(n, vi(n));

    set<int> s;
    for (int i = 1; i <= n * n; i++) s.insert(i);

    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c & 1) {
                ans[i][j] = *s.rbegin();
                s.erase(*s.rbegin());
            } else {
                ans[i][j] = *s.begin();
                s.erase(*s.begin());
            }
            c ^= 1;
        }
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                reverse(all(ans[i]));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
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