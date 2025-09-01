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
#define maxn 300
#else
#define debug(...)
#define maxn (3000005)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7;

int a[maxn];

void solve() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    function<int(int, int)> sol = [&](int l, int r) -> int {
        if (r - l == 1) return 0;
        int ans = 0;
        int mid = (l + r) / 2;
        int max_left = *max_element(a + l, a + mid);
        int max_right = *max_element(a + mid, a + r);  // [a + l, a + mid) // [a + mid, a + r)
        if (max_left > max_right) {
            ++ans;
            for (int i = 0; i < (mid - l); i++) {
                swap(a[l + i], a[mid + i]);
            }
        }
        return sol(l, mid) + sol(mid, r) + ans;
    };

    int ans = sol(0, m);
    if (is_sorted(a, a + m)) {
        cout << ans << "\n";
    } else {
        cout << -1 << '\n';
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