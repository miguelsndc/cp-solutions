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

ll c2(ll n) {
    return n * (n - 1) / 2;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // n participants split into m teams somehow
    // if m == 1 answer is n choose 2
    // if m > 1 the (n - m) choose 2 max with min 1
    ll n,m;cin>>n>>m;
    ll k = n / m;
    cout << m * (k * (k - 1)) / 2 + k * (n % m) << ' ' << c2(n - m + 1);
}