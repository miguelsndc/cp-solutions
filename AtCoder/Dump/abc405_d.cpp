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

#define fr(var, x, end) for (int(var) = x; (var) < (end); (var)++)

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (string& s : g) cin >> s;
    array<char, 4> dir = {'^', 'v', '<', '>'};
    vector<pair<pair<int, int>, char>> dirs = {{{0, 1}, '<'}, {{1, 0}, '^'}, {{-1, 0}, 'v'}, {{0, -1}, '>'}};
    auto can = [&](int i, int j) {
        if (i >= 0 and i < h and j >= 0 and j < w) {
            return (g[i][j] != 'E' and g[i][j] != '#' and (rg::find(dir, g[i][j]) == end(dir)));
        }
        return false;
    };
    queue<pii> q;

    fr(i, 0, h) {
        fr(j, 0, w) {
            if (g[i][j] == 'E') q.push({i, j});
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (auto [p, ch] : dirs) {
            auto [y, x] = p;
            if (can(r + y, c + x)) {
                g[r + y][c + x] = ch;
                q.push({r + y, c + x});
            }
        }
    }
    for (string& s : g) {
        cout << s << "\n";
    }
}

int main() {
    fast;
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}