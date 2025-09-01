#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;
namespace rg = std::ranges;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = rg::count(s, '1');
    if (c1 == 0 || c1 == n) {
        cout << 0 << '\n';
        return;
    }

    ll cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ans += min(cnt, c1 - cnt);
        } else {
            cnt++;
        }
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