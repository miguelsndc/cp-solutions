#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

vi visited(105, false);
vi color(105, -1);
vi g[105];
bool can = true;
bool dfs(int u, int c) {
    color[u] = c;
    visited[u] = true;
    can = true;
    for (int v: g[u]) {
        if (!visited[v]) {
            can = dfs(v, !c);
        } 
        if (color[v] == color[u]) {
            return false;
        }
    }
    return can;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while((cin >> x) && x) {
            g[i].push_back(x);
            g[x].push_back(i);
        }
    }

    bool can = true; 
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) can = dfs(i, 0);
        if (!can) break;
    } 
    if (can) {
        for (int i = 1; i <= n; i++) {
            cout << color[i];
        }
    } else {
        cout << -1 << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}