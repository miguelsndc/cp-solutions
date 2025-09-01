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
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int len = sqrt(n + .0) + 1;
    vector<unordered_map<int, int>> b(len);
    for (int i = 0; i < n; i++) {
        b[i / len][a[i]]++;
    }
    while (q--) {
        int t;
        cin >> t;
        if (t) {
            int l, r, x;
            cin >> l >> r >> x;
            --r;

            if (l > r) {
                cout << 0 << '\n';
                continue;
            }

            int bl = l / len, br = r / len;

            int cnt = 0;
            if (bl == br) {
                for (int i = l; i <= r; i++) {
                    if (a[i] == x) cnt++;
                }
                cout << cnt << "\n";
            } else {
                for (int i = l, end = (bl + 1) * len - 1; i <= end; i++) {
                    if (a[i] == x) cnt++;
                }
                for (int i = bl + 1; i <= br - 1; i++) {
                    cnt += b[i][x];
                }
                for (int i = br * len; i <= r; i++) {
                    if (a[i] == x) cnt++;
                }
                cout << cnt << "\n";
            }

        } else {
            int k, v;
            cin >> k >> v;
            int block = k / len;
            b[block][a[k]]--;
            b[block][v]++;
            a[k] = v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}