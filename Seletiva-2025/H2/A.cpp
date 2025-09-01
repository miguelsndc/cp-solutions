#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define fi first
#define se second
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x; cin >> n >> x;
    vector<pii> v(n);
    loop(i, 0, n){
        cin >> v[i].fi;
        v[i].se = i + 1;
    };

    sort(begin(v), end(v));

    int l = 0, r = n - 1;
    while(l < r) {
        if (v[l].fi + v[r].fi == x) {
            cout << v[l].se << ' ' << v[r].se;
            return 0;
        } else if (v[l].fi + v[r].fi > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << "IMPOSSIBLE";
}