#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

void solve() {
    i64 n, m, k; cin >> n >> m >> k;
    i64 l = 1, r = m, ans = - 1;
    while(l <= r) {
        i64 x = (l + r) / 2;
        i64 cnt = n * (m - m / (x + 1)); // fill k columns and skip 1 then k and skip 1 and so on
        if (cnt >= k) {
            r = x - 1;
            ans = r;
        } else {
            l = x + 1;
        }
    }
    cout << ans + 1 << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}