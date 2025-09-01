#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    int n, m; cin >> n >> m;
    vector<int> f(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        f[a]++, f[b]++;
    }

    int leaves = 0;
    for (int i = 0; i < n; i++) leaves += (f[i] == 1);
    int ans = 2 * (m / leaves);
    m %= leaves;
    ans += min(m, 2);
    cout << ans;
}