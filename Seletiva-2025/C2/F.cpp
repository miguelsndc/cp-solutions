#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> s(n + 1), appear(n + m + 1, -1), count(n + m + 1);

    for (ll i = 1; i <= n; i++) {
        cin >> s[i];
        appear[s[i]] = 0;
    }

    for (ll i = 1; i <= m; i++) {
        ll p, v; cin >> p >> v;
        ll prev = s[p];
        count[prev] += i - appear[prev];
        appear[prev] = -1;
        s[p] = v;
        appear[v] = i;
    }

    for (ll i = 1; i <= n + m; i++) {
        if (appear[i] != -1) count[i] += m + 1 - appear[i];
    }

    ll sum = 0;
    for (ll i = 1; i <= n + m; i++) {
        ll a = (m + 1) * m / 2;
        ll b = (m + 1 - count[i]) * (m - count[i]) / 2;
        if (count[i] > 0) sum += a - b;
    }

    cout << sum << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         solve();
    }
}