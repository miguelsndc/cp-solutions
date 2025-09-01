#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

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
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> s;
    for (int i = 1; i <= m; i++) {
        s.insert({0, i});
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pair<int, int> p = *s.begin();
        cout << p.second << ' ';
        s.erase(p);
        s.insert({p.first + val, p.second});
    }
    cout << "\n";
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