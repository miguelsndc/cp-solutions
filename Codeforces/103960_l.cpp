#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 1e5 + 5;
vector<ll> total_c(mxn), color(mxn), ans(mxn);
vector<vector<pair<int,int>>> tree(mxn);
map<ll,ll>* dfs(int u, int p)  {
    map<ll,ll> *freq = new map<ll,ll>();
    (*freq)[color[u]]++;

    for (auto [v, id]: tree[u]) {
        if (v == p) continue;

        auto child_freq = dfs(v, u);

        ll cnt = 0;
        for (auto [c, q]: *child_freq) {
            ll resto = total_c[c] - q;
            cnt += q * resto;
        }
        ans[id] = cnt;
        
        if(child_freq->size() > freq->size()) {
            swap(freq, child_freq);
        }
        for (auto [c, q] : *child_freq) {
            (*freq)[c] += q;
        }
        delete child_freq;
    }

    return freq;
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        total_c[color[i]]++;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        tree[--u].push_back({--v, i});
        tree[v].push_back({u, i});
    }

    dfs(0, -1);

    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << ' ';
    } 
}
int main() {
    int T = 1; // cin >> t;
    while(T--) solve();
}