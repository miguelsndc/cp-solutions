#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<ii>
#define vd vector<double>
#define si set<int>
#define mii map<int, int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n; cin >> n;
    int w[3][n];
    for (int i = 0; i < n; i++) cin >> w[0][i];
    for (int i = 0; i < n; i++) cin >> w[1][i];
    for (int i = 0; i < n; i++) cin >> w[2][i];
    int dp[8][n + 1];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        dp[1 << i][0] = w[i][0];
    }
    for (int day = 1; day < n; day++) {
        for (int mask = 0; mask < 8; mask++) {
            dp[mask][day] = dp[mask][day - 1];
            for (int activity = 0; activity < 3; activity++) {
                if (mask & (1 << activity)) {
                    dp[mask][day] = max(dp[mask][day], dp[mask^(1 << activity)][day - 1] + w[activity][day]);
                }
            }
        }
    }
    cout << dp[7][n - 1] << '\n';
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