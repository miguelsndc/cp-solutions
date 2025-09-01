#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

vector<int> g[101], visited(101);

bool find_n(int u, int t) {
    visited[u] = true;
    if (u == t) return true;
    bool can = false;
    for (int v: g[u]) {
        if (!visited[v]) {
            can |= find_n(v, t);
        }
    }
    return can;
}

void solve() {
    int n; cin >> n;
    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++) cin >> perm[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i - x >= 1) {g[i].push_back(i - x); g[i - x].push_back(i); }
        if (i + x <= n) {g[i].push_back(i + x); g[i + x].push_back(i); }
    }
    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        if (!find_n(i, perm[i])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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