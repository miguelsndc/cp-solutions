#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5 + 5;
ll gt[maxn];
vector<ll> comb(502);
void solve() {
    int n; cin >> n;
    if (!n) {
        cout << 1 << '\n';
        cout << 1 << " " << 1 << '\n';
        return;
    } 
    ll y = 0, x = 0;
    vector<pair<ll, ll>> pairs;
    while(n) {
        ll l = gt[n];
        for (ll i = 0; i < l; i++) {
            pairs.push_back({x++, y});
        }
        x += 2;
        y += 2; // sskipa pra proxima reta 
        n -= comb[l]; // l pares;
    }
    cout << pairs.size() << '\n';
    for (auto [a, b] : pairs) {
        cout << a << ' ' << b << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // precomputa i escolhe 2
    for (int i = 2; i < 502; i++) {
        comb[i] = i * (i - 1) / 2;
    }
    int j = 501;
    // maior quantidade de pares q ocnsigo
    for (int i = maxn - 1; i >= 1; i--) {
        while(comb[j] > i) j--;
        gt[i] = j;
    }
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}