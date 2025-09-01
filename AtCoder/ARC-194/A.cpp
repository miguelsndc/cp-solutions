#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    array<i64, 2> dp {-inf, 0LL};
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        dp[i % 2] = max(dp[i % 2], dp[(i + 1) % 2] + a);
    }
    cout << dp[(n + 1) % 2];
}