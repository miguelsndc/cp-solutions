#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, q; cin >> n >> q;
    vector<i64> ps(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ps[i + 1] = ps[i] + x;
    }
    while(q--) {
        int a, b; cin >> a >> b;
        cout << ps[b] - ps[a - 1] << '\n';
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