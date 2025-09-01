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
#define debug(x) cout << #x << " is: " << x << '\n';
#define se second
const int MAXN = 1e6 + 5;
 
const ll MOD1 = 1e9 + 9;
const ll MOD2 = 1e9 + 7;
const ll base = 53;
 
ll pow1[MAXN];
ll pow2[MAXN];
 
void precalc()
{
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow1[i] = (pow1[i - 1] * base) % MOD1,
        pow2[i] = (pow2[i - 1] * base) % MOD2;
}
 
struct PolyHash
{
    vector<pair<ll, ll>> pref;
 
    PolyHash(string &s)
    {
        pref = vector<pair<ll, ll>>(s.size() + 1, {0, 0});
 
        for (int i = 0; i < s.size(); i++)
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1,
            pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
    }
 
    ll get_hash(int a, int b)
    {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return ((h1 << 32LL)| h2);
    }
};
 

int main() 
{
    precalc();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, p; cin >> s >> p;
    int n = s.size(), m = p.size();
    PolyHash s_h(s); 
    PolyHash pt_h(p);
    ll cnt = 0;
    ll pattern_hash = pt_h.get_hash(0, m - 1);
    rep(i, 0, n - m + 1) {  
        if (s_h.get_hash(i, i + m - 1) == pattern_hash) {
            cnt++;
        }
    }
    cout << cnt;
}