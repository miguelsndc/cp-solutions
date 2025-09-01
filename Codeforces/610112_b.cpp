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

int n;
int compute_gcd(vector<int>& a) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = __gcd(a[i], cur);
    }
    return cur;
}

void solve() {
    map<int, int> seen;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        seen[a[i]] = 0;
    }

    if (compute_gcd(a) == 1) {
        cout << 0 << '\n';
        return;
    }

    int mincost = 1e9;
    for (int i = n; i >= 1; i--) {
        int x = __gcd(a[i], i);
        if (x == 1) {
            mincost = min(mincost, n - i + 1);
        };

        if (seen.count(x + 1)) {
            mincost = min(mincost, n - i + 1 + seen[x + 1]);
        }
        if (seen.count(x - 1)) {
            mincost = min(mincost, n - i + 1 + seen[x - 1]);
        }

        int tmp = a[i];
        a[i] = x;
        if (compute_gcd(a) == 1) {
            mincost = min(mincost, n - i + 1);
        }
        a[i] = tmp;

        if (!seen.count(x)) {
            seen[x] = n - i + 1;
        }
    }
    cout << mincost << '\n';
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