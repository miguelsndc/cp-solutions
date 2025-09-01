#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

#define all(x) begin((x)), end((x))

void solve() {
    int n; cin >> n;
    int k = 0;
    vector<int> v(n + 1); 
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    int po2 = 1;
    while(po2 * 2 <= n) po2 <<= 1;
    if (n & 1) {
        cout << n << '\n';
        int low = n & (-n);
        v[n - 3] = low;
        v[n - 2] = low + (low == 1 ? 2 : 1);
        v[n - 1] = n - low;
        v[n] = n;
    } else {
        cout << po2 * 2- 1 << '\n';
        if (n == po2) {
            v[n - 4] = 1, v[n - 3] = 3, v[n - 2] = n - 2, v[n - 1] = n - 1, v[n] = n;
        } else {
            v[n - 2] = n, v[n - 1] = n - 1, v[n] = po2 - 1;
        }
    }
    for (int i = 1; i <= n; i++) s.erase(v[i]);
    for (int i = 1; i <= n; i++) if (!v[i]) v[i] = *s.begin(), s.erase(v[i]);
    for (int i = 1; i <= n; i++) cout << v[i] << ' '; cout << '\n';
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