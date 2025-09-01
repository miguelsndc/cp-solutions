#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second

const int maxn = 1e6 + 5;
vector<ll> bit(maxn);
void add(int pos, int val) {
	++pos; 
	while (pos < maxn) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos) {
	++pos;
	int sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while(tc--) {
        ll n,m;cin>>n>>m;
        vector<ll> v (n); rep(i,0,n) cin>>v[i];
        vector<ll> ps(n+1); rep(i,0,n) ps[i+1] = ps[i] + v[i]; 
        rep(i,0, n+1)ps[i] %= m;
        ll total = 0, ps2 = 0;
        for (ll r = 0; r <= n; r++) {
            total += r * ps[r] - ps2 + (query(m + 1) - query(ps[r])) * m ; 
            ps2 += ps[r];
            add(ps[r], 1);
        }
        cout << total;
    }
}