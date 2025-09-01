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

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<ll> p1, p2;
    for (int i = l - 1; i <= r - 1; i++) {
        p1.push(a[i]);
        p2.push(a[i]);
    }

    for (int i = 0; i < l - 1; i++) {
        if (a[i] < p1.top()) {
            p1.pop();
            p1.push(a[i]);
        }
    }
    for (int i = r; i < n; i++) {
        if (a[i] < p2.top()) {
            p2.pop();
            p2.push(a[i]);
        }
    }

    ll aa = 0, b = 0;
    while (!p1.empty()) {
        aa += p1.top();
        p1.pop();
    }
    while (!p2.empty()) {
        b += p2.top();
        p2.pop();
    }

    cout << min({aa, b}) << "\n";
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