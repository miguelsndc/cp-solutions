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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == n)
            a[y]++;
        else if (y == n)
            a[x]++;
        else {
            cout << "NO\n";
            return;
        }
    }
    vector<int> s;
    for (int i = 1; i < n; i++) {
        if (!a[i]) s.push_back(i);
    }
    vector<pair<int, int>> ans;
    for (int i = n - 1; i; i--) {
        if (!a[i]) continue;
        a[i]--;
        int u = n, v;
        while (a[i]--) {
            v = s.back();
            s.pop_back();
            if (v > i) {
                cout << "NO\n";
                return;
            }
            ans.push_back({u, v});
            u = v;
        }
        ans.push_back({u, i});
    }
    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << "\n";
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