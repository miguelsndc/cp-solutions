#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

int maxn = 1005, maxm = 1005;
vector<vector<ll>> pref(maxn, vector<ll>(maxm, 0));

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<ll>> grid(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i + 1][j + 1] = (c == '*');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = grid[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int pr, pc, tr, tc; cin >> pr >> pc >> tr >> tc;
        cout << (
            pref[tr][tc] - pref[tr][pc - 1] 
          - pref[pr - 1][tc] + pref[pr - 1][pc - 1]
        ) << '\n';
    }
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