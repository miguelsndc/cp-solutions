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
constexpr int mod = 1e9 + 7, maxn = 2e4 + 5;

vector<int> parents(maxn);

void solve() {
    iota(all(parents), 0);
    int n;
    cin >> n;
    while (1) {
        char query;
        cin >> query;
        int x, y;
        if (query == 'O') break;
        if (query == 'E') {
            cin >> x;
            int sum = 0;
            while (parents[x] != x) {
                sum += abs(x - parents[x]) % 1000;
                x = parents[x];
            }
            cout << sum << '\n';
        } else {
            cin >> x >> y;
            parents[x] = y;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int tt = 1;
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
}