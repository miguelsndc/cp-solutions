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

const int ms = 1e6+5;
bool is_prime[ms];
int big_prime[ms];
void sieve(){
    fill(is_prime, is_prime + ms, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<ms; i++){
        if(is_prime[i]){
            big_prime[i] = i;
            for(int j=i+i; j<ms; j+=i){
                big_prime[j] = i;
                is_prime[j] = false;
            }
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n; cin >> n;
    rep(i,0,n) {
        ll x; cin >> x;
        ll sq = sqrt(x);
        if (sq * sq == x && is_prime[sq]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}