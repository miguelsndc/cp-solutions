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

const int maxn = 21;
int compatible[maxn][maxn];
vi dp(1 << maxn);
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compatible[i][j];
        }
    }

    dp[0] = 1;
    // itera sobre cada subset de mulheres
    for (int mask = 0; mask < (1 << n); mask++) {
        // n de mulheres
        int pairnum = __builtin_popcount(mask);
        for (int i = 0; i < n; i++) {
            // 
            if ((mask & (1 << i)) || !compatible[pairnum][i]) continue;
            dp[mask | (1 << i)] += dp[mask];
            dp[mask | (1 << i)] %= MOD;
        }
    }
    cout << dp[(1 << n) - 1];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}