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
    int tc; cin >> tc;
    while(tc--) {
        // chicken mcnugget theorem
        int n; cin >> n;
        rep(x,0,20) {
            if ((n % 11) == 0) {
                cout << "YES\n";
                goto done;
            } 
            n -= 111;
            if (n < 0) break;
        }
        cout << "NO\n";
        done:;
    }
}