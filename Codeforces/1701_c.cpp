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
    int n, m;
    cin >> n >> m;
    vector<int> prof(m), cnt(n);
    for (int i = 0; i < m; i++) {
        cin >> prof[i];
        prof[i]--;
        cnt[prof[i]]++;
    }

    // can it ocmplete in t hours ?
    auto check = [&](int t) -> int {
        ll uncomplete = 0, extra = 0;
        for (int i = 0; i < n; i++) {
            // can it complete its 1hr tasks
            if (t >= cnt[i]) {
                // if so then it can do this many tasks again
                extra += (t - cnt[i]) / 2;
            } else {
                // if not then
                uncomplete += cnt[i] - t;
            }
        }
        // do we complete it ?
        return uncomplete <= extra;
    };

    int l = 1, r = 2 * m, ans = 2 * m;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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