#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

const int MAXN = 1e5 + 5;
vector<vi> dp(MAXN, vi(2, -1));
vi g[MAXN];

ll dfs(int u, int p, int color) {
    if (dp[u][color] != -1) return dp[u][color];
    if (g[u].size() == 1 && g[u][0] == p) {
        return dp[u][color] = 1;
    }
    dp[u][color] = 1; ll w = -1, b = -1;
    for (int v: g[u]) {
        if (v != p) {
             w = dfs(v, u, 0);
            if (color == 0) {
                b = dfs(v, u, 1);
            }
            if (color == 0) {
                dp[u][color] = ((dp[u][color] % MOD) * ((w % MOD + b % MOD) % MOD)) % MOD;
            } else {
                dp[u][color] = ((dp[u][color] % MOD) * (w % MOD)) % MOD;
            }
        }
    }

    return dp[u][color];
}


void solve() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    g[0].push_back(1);
    g[1].push_back(0);

    dfs(0, -1, 0);
    cout << dp[0][0];
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