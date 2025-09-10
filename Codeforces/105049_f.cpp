#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int mod = 1e9 + 7, mxn = 1e6 + 5;
int freq[mxn][26] = {0}; 
ll fact[mxn];
ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int calc(int c) {
    int n = 0;
    ll s = 1;
    for (int i = 0; i < 26; i++) {
        n += freq[c][i];
        if (freq[c][i] > 0) {
            (s *= fact[freq[c][i]]) %= mod;
        }
    }
    return (fact[n] * fexp(s, mod - 2)) % mod;
};
void solve() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < mxn; i++) fact[i] = i * fact[i - 1] % mod;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        int equiv = i % k;
        freq[equiv][(int)(s[i] - 'a')]++;
    }
    ll prod = 1;
    for (int c = 0; c < k; c++) {
        (prod *= calc(c)) %= mod;
    }
    cout << prod % mod << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}