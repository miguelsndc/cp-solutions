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
    ll n, h;
    cin >> n >> h;
    vector<ll> start(n + 1);
    vector<ll> ps(n + 1);
    for (int i = 1; i <= n; i++) {
        int end;
        cin >> start[i] >> end;
        ps[i] = ps[i - 1] + end - start[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        while (l != r) {
            int mid = (l + r + 1) / 2;
            if ((start[mid] - start[i]) - (ps[mid - 1] - ps[i - 1]) < h) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, h + (ps[l] - ps[i - 1]));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}