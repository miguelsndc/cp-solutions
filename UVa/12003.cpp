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
    int n, m, u;
    cin >> n >> m >> u;
    int len = sqrt(n + .0) + 1;
    vector<int> a(n);
    vector<vector<ll>> b(len);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i / len].push_back(a[i]);
    }
    for (int i = 0; i < len; i++) sort(all(b[i]));
    while (m--) {
        int l, r, v, p;
        cin >> l >> r >> v >> p;
        --l, --r, --p;

        int bl = l / len, br = r / len, bp = p / len;

        int k = 0;
        if (bl == br) {
            for (int i = l; i <= r; i++) {
                if (a[i] < v) k++;
            }
        } else {
            for (int i = l, end = (bl + 1) * len - 1; i <= end; i++) {
                if (a[i] < v) k++;
            }
            for (int i = bl + 1; i <= br - 1; i++) {
                k += n - (lower_bound(all(b[i]), v + 1) - begin(b[i]));
            }
            for (int i = br * len; i <= r; i++) {
                if (a[i] < v) k++;
            }
        }
        b[bp].erase(lower_bound(all(b[bp]), a[p]));
        a[p] = u * k / (r - l + 1);
        b[bp].push_back(a[p]);
        sort(all(b[bp]));
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
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