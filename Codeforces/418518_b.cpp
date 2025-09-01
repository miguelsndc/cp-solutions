#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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
    string grid[2];
    cin >> n;
    cin >> grid[0] >> grid[1];
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (grid[0][i] != grid[1][i]) pos = i;
    }
    if (pos == -1) {
        cout << "YES\n";
        return;
    }

    int row = 1 - (grid[0][pos] == 'B'), ok = true;
    for (int i = pos + 1; i < n; i++) {
        if (grid[row][i] == 'W') {
            ok = false;
        }
        if (grid[row ^ 1][i] == 'B') {
            row ^= 1;
        }
    }
    row = 1 - (grid[0][pos] == 'B');
    for (int i = pos - 1; i >= 0; i--) {
        if (grid[row][i] == 'W') {
            ok = false;
        }
        if (grid[row ^ 1][i] == 'B') {
            row ^= 1;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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