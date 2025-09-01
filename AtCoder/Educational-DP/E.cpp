#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

int n, w, weight[105], value[105], dp[maxn];

void solve() {
    cin >> n >> w;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
        sum += value[i];
    }

    for (int i = 0; i < maxn; i++) dp[i] = 1e9 + 9;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int v = sum; v >= value[i]; v--) {
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }

    int maxv = 0;
    for (int i = 0; i <= sum; i++) {
        if (dp[i] <= w) maxv = i;
    }

    cout << maxv << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}
