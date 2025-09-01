#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n); vector<i64> ans(q);
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first; queries[i].second = i;
    }
    sort(all(queries));
    int j = 0; i64 ps = 0;
    for (int i = 0; i < q; i++) {
        while(j < n and queries[i].first >= v[j]) {
            ps += v[j]; 
            j++;
        }
        ans[queries[i].second] = ps;
    }
    for (i64 x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}