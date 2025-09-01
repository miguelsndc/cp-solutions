#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    ll total = n * n, can_attack = 0;
    ll dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    map<pll, bool> k;
    map<pll, bool> underattack;
    loop(i, 0, m) {
        ll y, x; cin >> y >> x;
        if(k.find({y, x}) != k.end()) {
            can_attack--;
        }
        k[{y, x}] = 1;
        loop(j, 0, 8) {
            ll ny = y + dy[j];
            ll nx = x + dx[j];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= n && k[{ny, nx}] == 0) {
                k[{ny, nx}] = 1;
                can_attack++;
            }
        }
    }
    cout << total - can_attack - m;
}