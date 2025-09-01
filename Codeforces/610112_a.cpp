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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (count(all(a), 0) == a.size()) {
        cout << 0 << '\n';
        return;
    }

    int cnt = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            cur++;
        else if (a[i] == 0 and cur > 0) {
            cnt++;
            cur = 0;
        }
    }
    if (cur > 0) cnt++;
    if ((cnt == 1) || (count(all(a), 0) == 0)) {
        cout << 1 << '\n';
        return;
    }

    cout << 2 << '\n';
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