#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    ll s = 0;
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                // 1 elemento o 1 jogador escolhe
                dp[l][r] = v[l];
            }  else {
                // se nao a escolha é o maximo entre 
                // - escolher o da esquerda e o que tiver no sufixo (jogador 2)
                // - escolher o da direito e o que tiver no prefixo (jogador 2)
                dp[l][r] = max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (s + dp[0][n - 1]) / 2;
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