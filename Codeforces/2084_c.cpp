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

int ans[maxn + 1][2], a[maxn], b[maxn], p[maxn];
int cnt = 0;
void faz(int x, int y) {
    if (x == y) return;
    ans[++cnt][0] = x;
    ans[cnt][1] = y;
    swap(a[x], a[y]);
    swap(p[a[x]], p[a[y]]);
    swap(b[x], b[y]);
}

void solve() {
    int n;
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (n % 2 == 0 || x) {
                cout << -1 << '\n';
                return;
            }
            x = i;
        } else if (b[p[b[i]]] != a[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    if (x and n & 1) {
        faz(x, (n + 1) / 2);
    }
    for (int i = 1; i <= n; i++) {
        faz(p[b[i]], n - i + 1);
    }
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
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