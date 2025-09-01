#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5, mxn = 2e6 + 5;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> op;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int pos = min_element(all(a)) - begin(a);
    int x = a[pos];
    for (int i = 0; i < n; i++) {
        if (i == pos) continue;
        op.push_back({pos + 1, i + 1, x, x + abs(pos - i)});
    }
    cout << op.size() << "\n";
    for (auto [a, b, c, d] : op) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
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