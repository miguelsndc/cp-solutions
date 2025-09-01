#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 1e6 + 10;
vector<bool> prime(mxn);
void solve() {
    int n, e; cin >> n >> e;
    vector<int> a(n);
    for (int &x:a) cin >> x;

    vector<vector<int>> b; vector<int> seen(n), cur;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        seen[i] = true;
        cur.clear();
        for (int j = i; j < n; j += e) {
            seen[j] = true;
            cur.push_back(a[j]);
        }
        b.push_back(move(cur));
    }
    ll ans = 0;
    for (vector<int> &v: b) {
        const int m = v.size();
        vector<ll> pre(m), suf(m);
        pre[0] = v[0] == 1;
        suf[m - 1] = v[m - 1] == 1;
        for (int i = 1; i < m; i++) {
            pre[i] = pre[i - 1] + (v[i] == 1);
            if (prime[v[i]] or v[i] != 1) pre[i] =0;
        }
        for (int i = m - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (v[i] == 1);
            if (prime[v[i]] or v[i] != 1) suf[i] =0;
        }
        for (int i = 0; i < m; i++) {
            if (prime[v[i]]) {
                int idx1 = max(i-1,0);
                int idx2 = min(i+1,m-1);
                ans += pre[idx1] + suf[idx2] + suf[idx2] * pre[idx1];
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(prime.begin(), prime.end(), 1);
    prime[0] = prime[1] = false;
    for (int i = 2; i < mxn; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j < mxn; j += i) {
                prime[j] = false;
            }
        }
    }

    int T = 1; cin >> T;
    while(T--) solve();
}