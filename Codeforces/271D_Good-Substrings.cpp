#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second
 
const ll MOD1 = (1 << 61) -1;
const ll MOD2 = (1 << 31) - 1;
const ll base = 123;
const int MAXN = 1505;
 
ll pow1[MAXN];
ll pow2[MAXN];
 
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
    PolyHash(string &s)
    {
        pref = vector<pair<ll, ll>>(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
            pref[i + 1].first = ((pref[i].first * base) % MOD1 + s[i]) % MOD1,
            pref[i + 1].second = ((pref[i].second * base) % MOD2 + s[i]) % MOD2;
    }
 
    pair<ll, ll> get_hash(int a, int b)
    {
        ll h1 = (MOD1 + pref[b + 1].first - (pref[a].first * pow1[b - a + 1]) % MOD1) % MOD1;
        ll h2 = (MOD2 + pref[b + 1].second - (pref[a].second * pow2[b - a + 1]) % MOD2) % MOD2;
        return {h1, h2};
    }
};

void solve() {
    calc_pow();
    string s; cin >> s;
    string good; cin >> good;
    int k; cin >> k;
    vector<int> is_good(256);
    for (int i = 0; i < 26; i++) {
        if (good[i] == '1') {
            is_good[i + 97] = true;
        }
    }

    PolyHash h(s);

    int n = s.size();
    vector<pair<ll, ll>> distinct;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (!is_good[s[j]]) cnt++;
            if (cnt <= k) {
                distinct.push_back(h.get_hash(i, j));
            }
        }
    }
    sort(begin(distinct), end(distinct));
    distinct.resize(unique(begin(distinct), end(distinct))- begin(distinct));
    cout << distinct.size();
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}