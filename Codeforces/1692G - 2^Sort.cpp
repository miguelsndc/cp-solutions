#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (v[i] < 2 * v[i + 1]) b[i] = true;
    }
    vector<int> ps(n);
    for (int i = 0; i < n - 1; i++) {
        ps[i + 1] = ps[i] + b[i];
    }
    int cnt = 0;
    int i = 0, j = k;
    while(j < n) {
        if (ps[j] - ps[i] == k) cnt++;
        j++, i++;
    }
    cout << cnt << '\n';
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