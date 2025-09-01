#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define ld long double
#define pii pair<int, int>

const ll INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;
const ld EPS = 1e-9;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<pair<int, int>> g[300005];
vector<bool> vis(300005);
vector<int> ans(300005);
queue<pair<int, int>> q;

void solve() {
    int n, k, d; cin >> n >> k >> d;
    for (int i = 0; i < k; i++) {
        int p; cin >> p;
        q.push({p, 0});
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    while (!q.empty()) {
        auto [pos, from] = q.front();
        q.pop();
        if (vis[pos]) continue;
        vis[pos] = true;
        for (const auto &[to, i]: g[pos]) {
            if (to == from) continue;

            if (vis[to]) ans[i] = 1;
            else q.push({to, pos});
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) if (ans[i]) cnt++;
    cout << cnt << '\n';
    for (int i = 1; i <= n - 1; i++) if (ans[i]) cout << i << ' ';

}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for(int t = 1; t <= tt; t++) {
         solve();
    }
}