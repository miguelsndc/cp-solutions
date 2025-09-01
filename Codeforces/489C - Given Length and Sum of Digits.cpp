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
    int m, s;cin>>m>>s;
    if (s == 0 && m == 1) {
        cout << 0 << ' ' << 0;
        return 0;
    } else if (s == 0 && m > 1) {
        cout << -1 << ' ' << -1;
        return 0;
    } else if (s > 9 * m) {
        cout << -1 << ' ' << -1;
        return 0;
    }

    vi big, small(m);
    int sm = s - 1;
    for (int i = m - 1; i>0; i--) {
        if (sm > 9) {
            small[i] = 9;
            sm -= 9;
        } else {
            small[i] = sm;
            sm = 0;
        }
    }

    small[0] = sm + 1;
    rep(i,0,m) cout<<small[i];
    cout << ' ';

    int no_nines = s/9;
    int rem = s % 9;
    rep(i,0,no_nines)big.push_back(9);
    big.push_back(rem);
    while(big.size() < m) big.push_back(0);
    rep(i,0,m) cout << big[i];
}