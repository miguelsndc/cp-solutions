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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

vector<int> closest(maxn, 1e9 + 9);

bool prf(int x) {
    int y = sqrt(x);
    return (y * y) == x;
}

void precompute() {
    int cur = maxn - 1;
    for (int i = maxn - 1; i >= 0; i--) {
        if (prf(i)) cur = i;
        closest[i] = cur;
    }
    closest[1] = 1;
    closest[0] = 0;
}

void solve() {
    precompute();
    int n;
    cin >> n;
    vector<int> values(n);
    iota(all(values), 0);
    reverse(all(values));
    int cur = closest[values[0]];
    vector<int> ans;
    for (int x : values) {
        if (cur - x == n - 2 || x == 1) cur = closest[x];
        ans.push_back(cur - x);
    }
    reverse(all(ans));
    for (int x : ans) {
        cout << x << ' ';
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