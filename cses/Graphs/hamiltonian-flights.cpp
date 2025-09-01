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
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

const int maxn = 20;
int dp[1 << maxn][maxn];
void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[maxn];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
    }
    dp[1][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        // nao inclui o primeiro elemento
        if ((mask & (1 << 0)) == 0) continue;
        // considera apenas rotas com a ultima cidade se for o subset completo
        // 100000 - 1 = 11111
        if ((mask & (1 << (n - 1))) == 0 && (mask != ((1 << n) - 1)) == 0) continue;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int v: g[i]) {
                // ja inclui
                if (mask & (1 << v)) continue;
                // mask que inclui v soma com a mask q nao inclui e tira o mod
                dp[mask | (1 << v)][v] += dp[mask][i];
                dp[mask | (1 << v)][v] %= MOD;
            }
        }
    }
    // subset completo no max de dias
    cout << dp[(1 << n) - 1][n - 1];
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