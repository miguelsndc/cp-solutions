#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define sz(x) (x.size())
namespace rg = std::ranges;

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
    int h, w, n;
    cin >> h >> w >> n;
    vector row(h + 1, vector<int>()), col(w + 1, vector<int>());
    vector<bool> q1(h + 1), q2(w + 1), vis(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        row[x].push_back(i);
        col[y].push_back(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            if (q1[x]) {
                cout << 0 << '\n';
                continue;
            }

            int cnt = 0;
            rg::for_each(row[x], [&](int i) {
                if (!vis[i]) vis[i] = true, cnt++;
            });
            q1[x] = true;
            cout << cnt << '\n';
        }
        if (t == 2) {
            if (q2[x]) {
                cout << 0 << '\n';
                continue;
            }

            int cnt = 0;
            rg::for_each(col[x], [&](int i) {
                if (!vis[i]) vis[i] = true, cnt++;
            });
            q2[x] = true;
            cout << cnt << '\n';
        }
    }
}
int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}