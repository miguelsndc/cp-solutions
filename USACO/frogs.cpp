#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n; cin >> n;
    int h[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        dp[i] = INT32_MAX;
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        // min cost to reach stone i
        if (i - 2 >= 1) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2])); 
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    }
    cout << dp[n];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
         solve();
    }
}