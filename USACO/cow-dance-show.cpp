#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, m) for (int(i) = 0; (i) < int(m); (i)++)

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
    int n, tmax;
    cin >> n >> tmax;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    auto check = [&](int k) -> int {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(d[i]);
        }
        int ptr = k, last = pq.top();
        while (!pq.empty()) {
            int finished = pq.top();
            last = finished;
            pq.pop();
            if (ptr < n) {
                pq.push(finished + d[ptr]);
                ptr++;
            }
        }

        return last <= tmax;
    };

    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
#ifndef CARNEDESOOOL
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}