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
constexpr int mod = 1e9 + 7, maxn = 3e5 + 5;

set<int> color[maxn];

void solve() {
    int n;
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        color[a[i]].insert(i);
    }
    int m;
    cin >> m;
    int jump[n + 1] = {0};
    while (m--) {
        int c;
        cin >> c;
        if (color[c].size() < 2) continue;
        int l = *color[c].begin();
        int r = *color[c].rbegin();
        for (int i = l; l <= r; i++) {
            if (jump[i]) i = jump[i];
            if (i > r) break;
            color[a[i]].erase(i);
        }
        jump[l] = r + 1;
    }
    for (int i = 1; i <= n;) {
        cout << a[i] << " \n"[i == n];
        if (jump[i]) {
            int cur = a[i];
            int en = jump[i];
            i++;
            while (i < en) {
                cout << cur << " \n"[i == n];
                i++;
            }
        } else {
            i++;
        }
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