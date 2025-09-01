#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<ll>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

bool f(ll maxw, ll x, vi& heights) {
    ll sum = 0;
    for (int i = 0; i < heights.size(); i++) {
        sum += max(x - heights[i], 0LL);
    }
    return sum > maxw;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        ll n, x; cin >> n >> x;
        ll maxcol = -1;
        vi corals(n); loop(i, 0, n) {
            cin >> corals[i]; maxcol = max(maxcol, corals[i]);
        };
        ll k = 0;
        for (ll b = maxcol; b >= 1; b /= 2) {
            while(!f(x, k + b, corals)) {
                k += b;
            }
        }

        cout << k << '\n';
    }
}