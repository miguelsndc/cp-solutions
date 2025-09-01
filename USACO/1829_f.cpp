#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 205;

void solve() {
    int n, m; cin >> n >> m;
    int cnt[n + 1];
    for (int i = 1; i<= n; i++) cnt[i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        cnt[u]++; cnt[v]++;
    }
    map<int,int> cnts;
    for (int i = 1; i<= n; i++) {
        cnts[cnt[i]]++;
    }
    vector<int> v;
    for (auto [_, x]: cnts) {
        v.push_back(x);
    }
    sort(begin(v), end(v));
    if (v.size() == 3) {
        cout << v[1] << ' ' << v[2]/v[1] << '\n';
    }  else {
        cout << v[0] - 1 << ' ' << v[1] / (v[0] - 1) << '\n'; 
    }
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