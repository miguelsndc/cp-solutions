#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

void solve() {
    int n, d;
    cin >> n >> d;
    vc<int> a(n), occ(1000001), deleted(1000001);
    for (int& x : a) {
        cin >> x;
        occ[x]++;
    }

    rg::sort(a);
    if (d == 0) {
        auto [f, l] = rg::unique(a);
        a.erase(f, end(a));
        cout << a.size() << '\n';
        return;
    }

    map<int, int> mp;
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (deleted[a[i]]) continue;
        if ((a[i] - d) > 0 and mp.count(a[i] - d)) {
            if (occ[a[i]] < occ[a[i] - d]) {
                deleted[a[i]] = true;
                mp.erase(a[i]);
            } else {
                deleted[a[i] - d] = true;
                mp.erase(a[i] - d);
            }
            mi += min(occ[a[i]], occ[a[i] - d]);
        }
        if (!deleted[a[i]]) mp[a[i]]++;
    }
    cout << mi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}