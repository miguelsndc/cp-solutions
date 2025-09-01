#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> jet(m);
    vector<array<int, 3>> f(n);
    for (int i = 0; i < n; i++) cin >> f[i][1] >> f[i][0], f[i][2] = i;
    for (int i = 0; i < m; i++) cin >> jet[i].first >> jet[i].second;
    sort(jet.begin(), jet.end());
    sort(f.begin(), f.end());
    int i = 0, j = 0; ll ps = 0;
    vector<ll> ans(n);
    map<ll, ll> at;
    while (i < n) {
        while(j < m and jet[j].first <= f[i][0]) {
            ps += jet[j].second; 
            at[jet[j].first] += jet[j].second;
            j++;
        }
        ll pos = f[i][1];
        pos += ps * 2;
        pos -= at[f[i][0]];
        ans[f[i++][2]] = pos;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}
