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
    int n, q;
    cin >> n >> q;
    vector<vi> a(n + 1, vi(n + 1));
    vector<vi> ps(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j + 1] = (s[j] == '*');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}