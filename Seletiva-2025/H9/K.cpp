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

const int MAXN = 1e6 + 5;

// caso tenha colisão use 1<<61 - 1 e 1<<31 -1 como mod e retorne um pair
 
const ll MOD1 = 1e9 + 7;
const ll base = 137;

ll pow1[MAXN];
void calc_pow()
{
    pow1[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow1[i] = pow1[i - 1] * base % MOD1;
}
 
struct PolyHash
{
    vector<ll> pref;
    PolyHash(string &s)
    {
        calc_pow();
        pref = vector<ll>(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++)
            pref[i + 1] = ((pref[i] * base) % MOD1 + s[i]) % MOD1;
    }
 
    ll operator()(int a, int b)
    {
        ll h1 = pref[b + 1] - (pref[a] * pow1[b - a + 1] % MOD1) % MOD1;
        return h1 + MOD1 * (h1 < 0);
    }
};


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    PolyHash hsh(s);
    int n = s.size();
    fori(s.size()) {
        int idx = 0;
        bool ok = true;
        while(idx < n) {
            int sz = min(i + 1, n - idx);
            if (hsh(0, sz - 1) != hsh(idx, idx + sz - 1)) {
                ok = false;
                break;
            }
            idx += sz;
        }
        if (ok) write(i + 1);
    }
}