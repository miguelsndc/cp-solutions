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
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) {
        s.insert(i);
    }
    a[1][n - 1] = *s.rbegin();
    s.erase(*s.rbegin());
    a[0][0] = *s.rbegin();
    s.erase(*s.rbegin());

    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (i == n - 1) break;
        a[cur][i] = *s.rbegin();
        s.erase(*s.rbegin());
        cur ^= 1;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        a[cur][i] = *s.begin();
        s.erase(*s.begin());
        cur ^= 1;
    }

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[j][i] << " \n"[i == n - 1];
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