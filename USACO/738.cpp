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

void solve() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    vc<ii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    sort(all(a));
    vc<int> c(n), q(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i].first;
        q[i] = a[i].second;
    }

    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        int x = c[l] + c[r];
        int v = min(q[l], q[r]);
        q[l] -= v;
        q[r] -= v;
        if (q[l] <= 0) l++;
        if (q[r] <= 0) r--;
        ans = max(ans, x);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}