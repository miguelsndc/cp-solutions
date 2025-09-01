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
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vi g(n); loop(i, 0, n) cin >> g[i];
        ll s = 0;
        map<ll, ll> mp;
        mp[0] = 1;
        bool found = false;
        loop(i, 0, n) {
            g[i] *= ((i % 2) ? -1: 1);
            s += g[i];
            if (mp[s]) {
                found = true;
                break;
            }
            mp[s]++;
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}