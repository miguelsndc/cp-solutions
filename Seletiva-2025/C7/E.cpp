#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n; cin >> n;
    map<int, int> up, down, diag1, diag2;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        up[x]++;
        down[y]++;
        diag1[x + y]++;
        diag2[x - y]++;
    }
    ll ans = 0;
    for (auto x: up) ans += x.second * (x.second - 1);
    for (auto x: down) ans += x.second * (x.second - 1);
    for (auto x: diag1) ans += x.second * (x.second - 1);
    for (auto x: diag2) ans += x.second * (x.second - 1);
    cout << ans << '\n';
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