#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<i64 ,i64>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first;
    for (int i = 0; i < n; i++) cin >> v[i].second;
    map<i64, i64> seen;
    for (const auto& [x, r]: v) {
        for (int xi = x - r; xi <= x + r; xi++) {
            seen[xi] = max(seen[xi], r * r - (x - xi) * (x - xi));
        }
    }
    i64 sum = 0;
    for (auto [_, val]: seen) {
        sum += 2 * (i64)sqrtl(val * 1.0) + 1;
    }
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
};
