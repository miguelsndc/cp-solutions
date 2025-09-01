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
    vector<i64> v(n);
    for (i64 &x: v) cin >> x;
    i64 sum = v[0], mx = v[0];
    for (int i = 1; i < n; i++) {
        sum = max(sum + v[i], v[i]);
        mx = max(mx, sum);
    }
    cout << mx << '\n';
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