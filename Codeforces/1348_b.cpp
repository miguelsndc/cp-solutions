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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    a.resize(unique(all(a)) - begin(a));

    if (a.size() > k) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= k; i++) {
        if (!count(all(a), i) and a.size() < k) {
            a.push_back(i);
        }
    }
    n = a.size();
    sort(all(a));
    cout << 100 * n << '\n';

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[j] << ' ';
        }
    }
    cout << '\n';
    // pattern of length k
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