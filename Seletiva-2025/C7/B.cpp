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
    int n, m; cin >> n >> m;
    if (n > m) {
        cout << 0;
        return;
    }
    ll result = 1;
    vi v(n); for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            result *= abs(v[i] - v[j]);
            result %= m;
        }
    }
    cout << result;
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