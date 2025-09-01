#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
namespace rg = std::ranges;

int n, m;
vc<int> state(10), c;
vc<vc<int>> zoos;
ll f(int i) {
    if (i == n) {
        vc<int> seen(m);
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) continue;
            cost += state[i] * c[i];
            for (int x : zoos[i]) {
                seen[x] += state[i];
            }
        }
        if (rg::all_of(seen, [](int x) { return x > 1; })) {
            return cost;
        } else {
            return (1e18);
        }
    }

    state[i] = 0;
    ll c1 = f(i + 1);
    state[i] = 1;
    ll c2 = f(i + 1);
    state[i] = 2;
    ll c3 = f(i + 1);

    return min({c1, c2, c3});
}

void solve() {
    cin >> n >> m;
    c.assign(n, 0);
    zoos.assign(n, vc<int>());
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            --a;
            zoos[a].push_back(i);
        }
    }
    cout << f(0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}