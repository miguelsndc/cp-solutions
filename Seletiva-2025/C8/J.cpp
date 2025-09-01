#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 4e6 + 5;
vi composite(maxn), num_primes(maxn), v(maxn), dp(maxn, -1);

void sieve(){
    for (int i = 2; i <= maxn; i++) {
        if (composite[i]) continue;
        for (int j = i; j <= maxn; j += i) {
            composite[j] = true;
            while(v[j] % i == 0) {
                v[j] /= i;
                num_primes[j]++;
            }
        }
    }
}

ll f(ll n) {
    if(n <= 1) return 0;
    if (dp[n] != -1) return dp[n];
    return dp[n] = 1 + f(n - num_primes[n]);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h; cin >> h;
    for (int i = 0; i <= maxn; i++) {
        v[i] = i;
    }
    sieve();
    ll ans = 0;
    for (int i = h; i > 1; i--){
        ans += f(i);
    }
    write(ans);
}