#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> g[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].insert(--b);
        g[b].insert(a);
    }
    int src = 0;
    vc<int> vis(n), perm(n - 1);
    iota(all(perm), 1);
    int cnt = 0;
    do {
        vis.assign(n, 0);
        vis[src] = true;
        int cur = src, can = true;
        for (int i = 0; i < n - 1; i++) {
            if (g[cur].count(perm[i])) {
                cur = perm[i];
            } else {
                can = false;
            }
        }
        if (can) cnt++;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}