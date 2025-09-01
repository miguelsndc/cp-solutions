#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    i64 cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i] - i%a[i]; j <= n; j += a[i]) {
            if (j > i) {
                cnt += (a[j] == (i + j)/a[i]);
            }
        }
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