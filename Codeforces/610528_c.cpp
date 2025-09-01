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
constexpr int mod = 1e9 + 7, maxn = 2e5;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int second = n, first = i, valid = true;
        // f[x] = n
        // fix x - 1
        // f[x] = f[x - 1] + f[x - 2]
        for (int i = 0; i < k - 2; i++) {
            int fx = first;
            // f[x-2] = f[x] - f[x - 1]
            first = second - fx;
            // second = x - 1;
            second = fx;

            /// valid if is increasing and all numbers are nonnegative
            // sequence is small ~log(n) base phi
            valid &= first <= second;
            valid &= min(first, second) >= 0;
            if (!valid) break;
        }
        if (valid) cnt++;
    }
    cout << cnt << '\n';
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