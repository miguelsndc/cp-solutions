#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>

const int maxw = 1e5 + 5;
const int maxn = 105;
vector<vi> dp(maxw, vi(maxn, -1));

// items (v, w)
ll sol = 0;
ll f(vii& items, int w, int i) {
    if (w <= 0) return 0;
    if (i >= items.size()) return 0;
    if (dp[w][i] != -1) return dp[w][i];

    ll ans = f(items, w, i + 1);
    if (items[i].first <= w) {
        ans = max(ans, items[i].second + f(items, w - items[i].first, i + 1));
        sol = ans;
    }
    return dp[w][i] = ans;
}

void solve() {
    int n, w; cin >> n >> w;
    vii items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    f(items, w, 0);
    cout << sol;
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