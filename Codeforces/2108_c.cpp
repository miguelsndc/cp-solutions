#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

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
    vector<int> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if
    }
    a.push_back({-1, -1});
    sort(rall(a));
    vector<vi> order;
    vi cur;
    int mn = a[0].first;
    for (int i = 0; i < n + 1; i++) {
        if (a[i].first == mn) {
            cur.push_back(a[i].second);
        } else {
            sort(all(cur));
            order.push_back(cur);
            cur.clear();
            cur.push_back(a[i].second);
        }
        mn = min(mn, a[i].first);
    }

    set<int> seen;
    int ans = 0;
    for (auto v : order) {
        for (int x : v) {
            if (!seen.count(x) and !seen.count(x - 1) and !seen.count(x + 1)) {
                ans++;
            }
            seen.insert(x);
        }
    }
    cout << ans << '\n';
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