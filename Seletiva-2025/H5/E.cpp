#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

const int MAXN = 2e5 + 5;
vector<int> g[MAXN];
vector<vi> dp(2, vi(MAXN, 0));

void tree_match(int u, int p = -1) {
    int sum1 = 0, sum2 = 0;
    for (int v: g[u]) {
        if (v != p) {
            tree_match(v, u);
            sum1 += max(dp[0][v], dp[1][v]);
        }
    }
    dp[0][u] = sum1;
    for (int v: g[u]) {
        if (v != p) {
            sum2 = max(sum2, 1 + dp[0][v] + dp[0][u] - max(dp[0][v], dp[1][v]));
        }
    }
    dp[1][u] = sum2;
} 

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tree_match(1);
    cout << max(dp[1][1], dp[0][1]);
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