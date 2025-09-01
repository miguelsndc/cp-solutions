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
        int n, k; cin >> n >> k;
        /*
            Represent the number n
            as the sum of k
            positive integers of the same parity (have the same remainder when divided by 2
            ).

            if (n % k == 0) then n / k  k times
            otherwise print n / k k - 1 times and check if n / k and n / k + n % k have the same parity
        */
        if (n % k == 0) {
            cout << "YES\n";
            rep (i,0,k) cout << n/k << " \n"[i == k -1];
        } else {
            int x = n - 2 * (k - 1);
            int y = n - (k - 1);
            if (x % 2 == 0 && x > 0) {
                cout << "YES\n";
                rep(i,0,k - 1) cout << 2 << ' ';
                cout << x << '\n';
            } else if (y & 1 && y > 0) {
                cout << "YES\n";
                rep(i,0,k-1) cout << 1 << ' ';
                cout << y << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
}