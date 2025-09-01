#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define x first
#define y second

using ld = long double;
#define pt pair<ld, ld>

ld dist(pt a, pt b) {
    return hypot(a.x - b.x, a.y - b.y);
}

pt circumcenter(pt A, pt B, pt C) {
    ld D = 2 * (A.x * (B.y - C.y) +
                B.x * (C.y - A.y) +
                C.x * (A.y - B.y));

    ld Ux = ((A.x * A.x + A.y * A.y) * (B.y - C.y) +
             (B.x * B.x + B.y * B.y) * (C.y - A.y) +
             (C.x * C.x + C.y * C.y) * (A.y - B.y)) /
            D;

    ld Uy = ((A.x * A.x + A.y * A.y) * (C.x - B.x) +
             (B.x * B.x + B.y * B.y) * (A.x - C.x) +
             (C.x * C.x + C.y * C.y) * (B.x - A.x)) /
            D;

    return {Ux, Uy};
}

void solve() {
    int n;
    cin >> n;
    vc<pt> a(n);
    for (int i = 0; i < n; i++) {
        int o, s;
        cin >> o >> s;
        a[i].y = s * 1.0;
        a[i].x = o * 1.0;
    }

    vc<ld> ans(n * n, numeric_limits<ld>::max());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld radius = dist(a[i], a[j]) / 2;
            ld center_x = (a[i].x + a[j].x) / 2;
            ld center_y = (a[i].y + a[j].y) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (hypot(a[i].x - center_x, a[i].y - center_y) <= radius) {
                    cnt++;
                }
            }
            ans[cnt * (cnt - 1) / 2] = min(ans[cnt * (cnt - 1) / 2], radius);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                pt center = circumcenter(a[i], a[j], a[k]);
                ld radius = max({dist(a[i], center), dist(a[j], center), dist(a[k], center)});
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (dist(a[i], center) <= radius) {
                        cnt++;
                    }
                }
                ans[cnt * (cnt - 1) / 2] = min(ans[cnt * (cnt - 1) / 2], radius);
            }
        }
    }

    cout << setprecision(10) << fixed;
    for (int i = n * (n - 1) / 2; i >= 1; i--) {
        ans[i] = min(ans[i + 1], ans[i]);
    }
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}