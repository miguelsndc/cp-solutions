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
    set<int> bits[20];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int m = 0; m < 20; m++) {
            if ((a[i] & (1 << m)) == 0) {
                bits[m].insert(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int maxl = 0, minr = n - 1;
        for (int m = 0; m < 20; m++) {
            if (a[i] & (1 << m)) {
                auto it = bits[m].lower_bound(i);
                if (it != bits[m].end())
                    minr = min(minr, *it - 1);
                if (it != bits[m].begin())
                    maxl = max(maxl, *prev(it) + 1);
            }
        }
        cout << 1LL * (minr - i + 1) * (i - maxl + 1) << " ";
    }
    cout << '\n';
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