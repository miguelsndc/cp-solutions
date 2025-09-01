#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vector<ii> v(n + 1); 
    vector<ll> ans(n + 1); 
    ll suf = 0, pref = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi;
        v[i].se = i;
        suf += v[i].fi;
    }
    sort(begin(v), end(v));
    for (int i = 1; i <= n; i++) {
        suf -= v[i].fi;
        pref += v[i].fi;
        ans[v[i].se] = n + 1LL * v[i].fi * (2 * i - n) - pref + suf;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
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