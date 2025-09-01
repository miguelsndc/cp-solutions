#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n; cin >> n;
    string mat[n + 1];
    for (int i = 0; i <= n; i++) cin >> mat[i];
    ll dp[(1 << n)];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            bool win = (mat[0][i] == '1');
            for (int j = 0; j < n && !win; j++) {
                if (mask & (1 << j)) {
                    win = win | (mat[j + 1][i] == '1');
                }
            }
            if (win) {
                dp[mask | (1 << i)] += dp[mask];
                dp[mask | (1 << i)] %= MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}