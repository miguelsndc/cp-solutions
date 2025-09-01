#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

i64 lcm(i64 a, i64 b) {
    return a * b / __gcd(a, b);
}

void solve() {
    int n; cin >> n;
    vector<i64> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    bool ok = true;
    // i64 cur_lcm = 1;
    // for (int i = 0; i < n; i++) {
    //     cur_lcm = lcm(cur_lcm, v[i]);
    // }
    for (int i = 0; i < n - 1; i++) {
        i64 cur_lcm = lcm(v[i], v[i + 1]);
        int x = cur_lcm / v[i], y = cur_lcm / v[i + 1];
        while(x) {
            if (x % 2 == 0) x /= 2;
            else if (x % 3 == 0) x /= 3;
            else if (x == 1) break;
            else break;
        }
        while(y) {
            if (y % 2 == 0) y /= 2;
            else if (y % 3 == 0) y /= 3;
            else if (y == 1) break;
            else break;
        }

        int okx = x == 1;
        int oky = y == 1;
        ok &= okx && oky;
    }
    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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