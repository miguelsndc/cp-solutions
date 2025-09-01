#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = i;
    }

    sort(all(a));

    auto pega = [&](int k) {
        int x[] = {0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 6; i++) {
            x[i] = k % 10; k /= 10;
        }
        return abs((x[3] + x[4] + x[5]) - (x[0] + x[1] + x[2]));
    };

    vector<int> cnt(30), ans(n);

    int cur = 0;
    for (auto [val, i]: a) {
        for (; cur < val; cur++) {
            cnt[pega(cur)]++;
        } 
        int k = pega(val), x = 0;
        for (int j = 0; j < k; j++) {
            x += cnt[j];
        }
        ans[i] = x;
    }

    for (int x: ans) {
        cout << x << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}