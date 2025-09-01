#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define vc vector

void solve() {
    int n;
    cin >> n;
    vc<pair<int, int>> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    int mx = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                set<int> s{a[i].second, b[j].second, c[k].second};
                if (s.size() == 3) {
                    mx = max(a[i].first + b[j].first + c[k].first, mx);
                }
            }
        }
    }
    cout << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}