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

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 5e4 + 5;

vector<int> par(maxn), sz(maxn, 1);

void solve() {
    function<int(int)> find = [&](int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    };

    function<int(int, int)> join = [&](int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (sz[xr] > sz[yr]) swap(xr, yr);
        sz[xr] += sz[yr];
        par[yr] = xr;
        return true;
    };

    int c, r;
    while ((cin >> c >> r), (c || r)) {
        iota(all(par), 0);
        fill(all(sz), 1);
        map<string, int> mp;
        int cur = 0;
        for (int i = 0; i < c; i++) {
            string s;
            cin >> s;
            if (!mp.count(s)) mp[s] = cur++;
        }
        for (int i = 0; i < r; i++) {
            string a, b;
            cin >> a >> b;
            join(mp[a], mp[b]);
        }
        cout << *max_element(all(sz)) << '\n';
        cin.ignore();
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