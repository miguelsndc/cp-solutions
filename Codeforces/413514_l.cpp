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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), tmp(n);
    for (int i = 0; i < n; i++) cin >> a[i], tmp[i] = i;
    for (int i = 0; i < n; i++) cin >> b[i];

    auto cmp = [&](int i, int j) -> bool {
        if (a[i] == a[j]) {
            return b[i] < b[j];
        }
        return a[i] < a[j];
    };

    sort(all(tmp), cmp);

    for (int i = 0; i < n - 1; i++) {
        if (a[tmp[i]] > a[tmp[i + 1]] || b[tmp[i]] > b[tmp[i + 1]]) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<pair<int, int>> moves;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1] || b[j] > b[j + 1]) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                moves.push_back({j + 1, j + 2});
            }
        }
    }

    cout << moves.size() << '\n';
    for (auto [i, j] : moves) {
        cout << i << ' ' << j << '\n';
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