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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int j = 0;
    for (int i = 0; i < n and j < m; i++) {
        if (a[i] >= b[j]) j++;
    }
    if (j == m) {
        cout << "0\n";
        return;
    }

    vector<int> s(m, n);
    j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m and a[i] >= b[j]) {
            s[j] = i, j++;
        }
    }

    int slen = j;
    vector<int> t(m, -1);
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 and a[i] >= b[j]) {
            t[j] = i, j--;
        }
    }
    int ans = INT_MAX;
    for (int j = 1; j <= m; j++) {
        int need_before = j - 1, need_after = m - j;
        if (need_before > slen) continue;
        int pos_before = need_before == 0 ? -1 : s[need_before - 1];
        int pos_after = need_after == 0 ? n : t[m - need_after];
        if (pos_after == -1 or pos_before >= pos_after) continue;
        ans = min(ans, b[j - 1]);
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
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