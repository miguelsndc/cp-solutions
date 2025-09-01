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
    cin >> n;
    vector<int> a(n);
    int negcnt = 0, poscnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        (a[i] < 0 ? negcnt++ : poscnt++);
    }
    if (n & 1) {
        cout << -1 << "\n";
        return;
    }
    vector<pair<int, int>> segs;
    for (int l = 0; l < n; l++) {
        if (l + 1 < n and a[l] != a[l + 1]) {
            segs.push_back({l + 1, l + 1});
            segs.push_back({l + 2, l + 2});
            l++;
        } else if (l + 1 < n and a[l] == a[l + 1]) {
            segs.push_back({l + 1, l + 2});
            l++;
        }
    }
    cout << segs.size() << '\n';
    for (auto [x, y] : segs) {
        cout << x << ' ' << y << '\n';
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