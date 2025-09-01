#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x; cin >> x;
    ll res = 0;
    vi d;
    while(x > 0) {
        int y = x % 10;
        d.push_back(y);
        x /= 10;
    }
    reverse(d.begin(), d.end());
    int i = (d[0] == 9);
    if (d[0] == 9) cout << 9;
    for (; i<d.size();i++) {
        if (9 - d[i] < d[i]) {
            d[i] = 9 - d[i];
        } 
        cout << d[i];
    }
}