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

const int MAXN = 5001;
vector<ii> g[MAXN];
int threshold, cnt = 0;

void dfs(int u, int parent) {
    for (const auto &[v, w]: g[u]) {
        if (v != parent && w >= threshold) {
            cnt++;
            dfs(v, u);
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int p, q, r; cin >> p >> q >> r;
        g[p].push_back({q, r});
        g[q].push_back({p, r});
    }

    while(q--) {
        int v; cin >> threshold >> v;
        cnt = 0;
        dfs(v, 0);
        cout << cnt << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("mootube");
    #endif
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}