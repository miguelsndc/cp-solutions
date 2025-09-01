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
    vector<i64> v(n), cnt(32); for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            if ((v[i] >> j) & 1) {
                cnt[j]++;
            }
        }
    }
    i64 maxs = 0;
    for (int i = 0; i < n; i++) {
        i64 total = 0;
        for (int j = 0; j < 31; j++) {
            i64 cnt1 = cnt[j];
            i64 cnt0 = n - cnt1;
            if ((v[i] >> j) & 1) {
                total += cnt0 * (1 << j);
            } else {
                total += cnt1 * (1 << j);
            }
        }
        maxs = max(maxs, total);
    }
    cout << maxs << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}