#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    u64 x, y; cin >> x >> y;
    if ((x == y)) {cout << -1 << '\n'; return; }
    if ((x & y) == 0) {cout << 0 << '\n'; return; }
    u64 z = max(x, y), v = 1; 
    while(v < z) v <<= 1;
    cout << v - z << '\n';
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