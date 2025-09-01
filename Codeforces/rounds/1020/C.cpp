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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (count(all(b), -1) == n) {
        vector<int> minval(n), maxval(n);
        for (int i = 0; i < n; i++) {
            minval[i] = a[i];
            maxval[i] = a[i] + k;
        }
        int min_s = *max_element(all(minval));
        int max_s = *min_element(all(maxval));

        ll ways = max(0, max_s - min_s + 1);
        cout << ways << '\n';
        return;
    }

    int target = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            target = a[i] + b[i];
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] != -1 and a[i] + b[i] != target) {
            cout << 0 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            int val = target - a[i];
            if (val < 0 || val > k) {
                cout << 0 << "\n";
                return;
            }
        }
    }

    cout << 1 << '\n';
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