#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

bool f(ll m, vii &attacks, ll h) {
    ll total = 0;
    for (const auto&[dmg, cd]: attacks) {
        total += ((m / cd) + 1) * dmg;
        if (total >= h) {
            return true;
        }
    }
    return total >= h;
}

void solve() {
    ll h, n; cin >> h >> n;
    vii attacks(n);
    for (int i = 0; i < n; i++) {
        cin >> attacks[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> attacks[i].second;
    }

    ll l = 0, r = 5e11,ans = 0;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        if(m == 0) {
            int a = 2;
        }
        if (f(m, attacks, h)) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    cout << ans + 1 << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  cin >> tt;
    while(tt--) {
         solve();
    }
}