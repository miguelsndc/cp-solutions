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


ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
ll inv(ll a){ 
    return fexp(a, MOD - 2);
}
ll fact[4000001];
ll comb(ll n, ll k){
    return ((fact[n] * inv(fact[k]) % MOD) * inv(fact[n-k])) % MOD;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 4000000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll n, m; cin >> n >> m;
    writeln(comb(n + m - 1, m));
}