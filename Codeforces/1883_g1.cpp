#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> b;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.insert(x);
    }

    int op = 0;
    sort(all(a));
    for (int x : a) {
        auto it = b.upper_bound(x);
        if (it == end(b)) {
            op++;
            b.erase(b.lower_bound(0));
        } else {
            b.erase(b.upper_bound(x));
        }
    }
    cout << op << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}