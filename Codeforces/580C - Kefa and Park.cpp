#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 1e5 + 5;

vi is_cat(maxn);
vi g[maxn];
vi out(maxn);
int n, m;
ll cnt = 0;

void dfs(int u, int p, int curr) {
    if (curr > m) return;
    int ok = 1;
    for (int v : g[u]) {
        if (v != p) {
            ok = 0;
            dfs(v, u, curr * is_cat[u] + is_cat[v]);
        }
    }
    cnt += ok;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n + 1) cin >> is_cat[i];
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        out[a]++, out[b]++;
    }
    dfs(1, -1, is_cat[1]);
    cout << cnt;
}