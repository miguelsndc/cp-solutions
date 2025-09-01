#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> g[1001];
vector<bool> visited(1001);
int seen = 0;
void dfs(int u) {
    if (seen != 0) return;
    visited[u] = true;
    for (int v: g[u]) {
        if (visited[v]) {
            if(seen == 0) seen = v;
        } else {
            dfs(v);
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        g[i].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
        cout << seen << ' ';
        seen = 0;
        fill(begin(visited), end(visited), false);
    }
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