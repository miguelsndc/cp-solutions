#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second


void solve() {
    int n; cin >> n;
    int trie[9 * (n + 5)][2], z = 1;
    memset(trie[0], -1, sizeof trie);

    auto insert = [&] (ll pxor, ll msb) {
        bool val; int cur = 0;
        for (ll b = msb; b >= 0; b--) {
            val = pxor & (1 << b);
            if (trie[cur][val] == -1) { 
                memset(trie[z], -1, sizeof trie[z]);
                trie[cur][val] = z++;
            }
            cur = trie[cur][val];
        }
    };

    auto query = [&] (ll pxor, ll msb)->int {
        bool val; int cur = 0,  res = 0;
        for (int b = msb; b >= 0; b--) {
            val = pxor & (1 << b);
            if (trie[cur][!val] != -1) cur = trie[cur][!val], res |= (1 << b);
            else if (trie[cur][val] != -1) cur = trie[cur][val];
        }
        return res;
    };

    vector<int> a(n);
    for (int &x:a) cin>>x;
    int mx = *max_element(all(a));
    int msb = __builtin_clz(mx | 1);
    int root = 1;
    insert(0, msb);
    int res = 0, pxor = 0;
    for (int i = 0; i < n; i++) {
        pxor ^= a[i];
        insert(pxor, msb);
        res = max(res, query(pxor, msb));
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}