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
int sz = (1 << 27);
vector<int> leftmost(sz, sz);
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mask = 0, best = 1;
    leftmost[0] = -1;
    for (int i = 0; i < n; i++) {
        mask ^= (1 << (s[i] - 'a'));
        if (leftmost[mask] != sz) {
            best = max(best, i - leftmost[mask]);
        }
        for (int mk = 0; mk < 27; mk++) {
            int pos = (mask ^ (1 << mk));
            if (leftmost[pos] != sz) {
                best = max(best, i - leftmost[pos]);
            }
        }
        if (leftmost[mask] == sz) {
            leftmost[mask] = i;
        }
    }
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}