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
#define sz(x) int((x).size())
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n, m; cin >> n >> m;
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        string s; ll x; cin >> s >> x;
        mp[sz(s)] = max(1LL * mp[sz(s)], x);
    }

    const int maxn = 2e5 + 5;
    vll dp(maxn);
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        for (const auto &[cost, v]: mp) {
            if (i - cost >= 0) {
                dp[i] = max(dp[i], dp[i - cost] + v);
            }
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[m];
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