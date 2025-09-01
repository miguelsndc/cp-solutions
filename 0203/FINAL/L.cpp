#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2005;

vector<int> g[maxn];

int maxd = -1;
void dfs(int u, int p = -1, int d = 1) {
    maxd = max(maxd, d);
    for (int v: g[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x != -1) {
            g[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    cout << maxd;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}