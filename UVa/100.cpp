#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end() 
class SparseTable {
    private:
        int n, k;
        vector<vector<int>> st;
    public: 
    SparseTable(const vector<int> & v) {
        n = v.size(); k = 31 - __builtin_clz(n) + 1;
        st.resize(k); st[0] = v;
        for (int i = 1; i < k; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) 
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    int query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return max(st[p][l], st[p][r - (1 << p) + 1]);
    }
};
void solve() {
    const int mxn = 1e6 + 5;
    vector<int> dp(mxn);
    dp[1] = 1;
    for (ll i = 2; i < mxn; i++) {
        ll k = i;
        int cnt = 1;
        while(1) {
            if (k & 1) k = 3 * k + 1;
            else k /= 2;
            cnt++;
            if (k == 1) {
                dp[i] = cnt;
                break;
            }
        }
    }
    SparseTable st(dp);
    int i, j;
    while((cin >> i >> j)) {
        auto [l, r] = minmax(i, j);
        int ans = st.query(l, r);
        cout << i << ' ' << j << ' ' << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}