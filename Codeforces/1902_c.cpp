#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

#define int long long

void solve() {	
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for (int &x: a) cin >> x, mp[x] = 1;
    int gdiff = 0, mx = *max_element(all(a));
    for (int &x: a)  {
        gdiff = __gcd(mx - x, gdiff);
    }
    gdiff = max(gdiff, 1LL);
    int op = 0;
    for (int &x: a) {
        int diff = mx - x;
        op += diff / gdiff;
    }
    int extra = n;
    for (int j = mx;; j -= gdiff) {
        if (!mp.count(j)) {
            extra = min(extra, (mx - j) / gdiff);
            break;
        }
    }
    cout << op + extra << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}