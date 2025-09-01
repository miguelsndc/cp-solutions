#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
template<typename T> class SparseTable {
    private:
        int n, k;
        vector<vector<T>> st;
    public: 
    SparseTable(const vector<T> & v) {
        n = v.size(); k = 31 - __builtin_clz(n) + 1;
        st.resize(k); st[0] = v;
        for (int i = 1; i < k; i++) {
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) 
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return max(st[p][l], st[p][r - (1 << p) + 1]);
    }
};
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, d, k; cin >> n >> d >> k;
        vector<pair<int,int>> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i].first >> a[i].second;
            --a[i].first, --a[i].second;
        }
        sort(a.begin(), a.end());
        multiset<int> ms;
        int b = 0, m = 0, mn = 1e9, mx = -1;
        for (int i = 0, j = 0; i + d - 1 < n; i++) {
            while(j < k and a[j].first <= i + d - 1) {
                ms.insert(a[j].second);
                j++;
            }
            while(!ms.empty() and *ms.begin() < i) {
                ms.erase(ms.begin());
            }

            int cnt = ms.size();
            if (cnt < mn) {
                mn = cnt;
                m = i;
            }
            if (cnt > mx) {
                mx = cnt;
                b = i;
            }
        }
        cout << b + 1 << ' ' << m + 1 << '\n';
    }
}
