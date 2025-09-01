#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

const int INF = 1e9 + 1;

void solve() {
    int n, x; cin >> n >> x;
    vi dp(x + 1, INF), coins(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 1; i <= x; i++) {
        for (int c: coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
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