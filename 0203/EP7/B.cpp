#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
ll power(ll b, ll p, ll m) {
    long long x = 1;
    ll power = b % m;
    ll k = log2(p);
    for (ll i = 0; i <= k; i++) {
       ll a = (p >> i) & 1;
       if (a == 1)
           x = (x * power) % m;
       power = (power * power) % m;
   }
    return x;
}

void solve() {
    int n; cin >> n;
    ll zero = 0, one = 0, s = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 0) zero++;
        if(x == 1) one++;
        s += x;
    }
    ll res = 1;
    for (int i = 0; i < zero; i++) {
        res *= 2;
    }
    cout << one * res << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}