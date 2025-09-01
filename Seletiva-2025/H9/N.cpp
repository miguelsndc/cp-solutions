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

const int MAXN = 2e5 + 5;

// caso tenha colisão use 1<<61 - 1 e 1<<31 -1 como mod e retorne um pair
 
const ll MOD1 = 188'888'881;
const ll MOD2 = 1e9 + 7;
const ll base = 137;
 
ll pow1[MAXN];
ll pow2[MAXN];
 
bool called = false;
void calc_pow()
{
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow1[i] = (pow1[i - 1] * base) % MOD1,
        pow2[i] = (pow2[i - 1] * base) % MOD2;
}
 
struct PolyHash
{
    vector<pair<ll, ll>> pref;
    PolyHash(vector<ll> &s)
    {
        if(!called) {
            calc_pow();
            called = true; // pra garantir q so chama uma vez por hash e q eu nao va esquecer essa bomba
        }

        pref = vector<pair<ll, ll>>(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1,
            pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
    }
 
    ll operator()(int a, int b)
    {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return (h1 << 32LL) | h2;
    }
};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w; cin >> n >> w;
    if (w == 1) {
        writeln(n);
        return 0;
    }
    vector<ll> a(n), b(w), difa(n - 1), difb(w - 1);
    fori(n) cin >> a[i];
    fori(w) cin >> b[i];
    fori(n - 1) difa[i] = a[i] - a[i + 1];
    fori(w - 1) difb[i] = b[i] - b[i + 1];

    PolyHash ha(difa), hb(difb);
    ll cnt = 0, nn = n - 1, ww = w - 1;
    for (int i = 0; i < nn - ww + 1; i++) {
        if (ha(i, i + ww - 1) == hb(0, ww - 1)) {
            cnt++;
        } 
    }
    writeln(cnt);
}