#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define db double
#define MOD 1000000007
#define ii pair<int, int>

typedef pair<ll, ll> node;

const int MAXN = 2e5 + 1;
const db EPS = 1e-9;

vector<ii> adj[MAXN];
vector<bool> vis(MAXN);
node val[MAXN]; bool possible = true, found = false;
db ans[MAXN];
node x;

vector<int> component;

void dfs(int u, int p) {
    vis[u] = true;
    component.push_back(u);
    for (const auto&[v, type]: adj[u]) {
        if (v == p) continue;
        node tmp = {val[u].first * -1ll, type - val[u].second};
        if (!vis[v]) {
            val[v] = tmp;
            dfs(v, u);
       } else {
            if (val[v].first == tmp.first) {
                if(val[v].second != tmp.second){
                    possible = false;
                    return;
                }
            } else {
                node tx = {tmp.first - val[v].first, val[v].second - tmp.second};
                if (!found) { x = tx; found = true; }
                else if (x.first * tx.second != x.second * tx.first) {
                    possible = false;
                    return;
                }
            }
       }
    }
}

db f(db y) {
    db res = 0;
    for (int u: component) {
        res += fabs(y * (db)val[u].first + (db) val[u].second);
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for (int i = 1; i <= n && possible; i++) {
        if (vis[i]) continue;
        val[i] = {1, 0};
        found = false;
        component.clear();
        dfs(i, -1);
        db xx = 0;
        if (found) {
            xx = (db) x.second / (db) x.first;
        } else {
            db l = -100000000, r = 100000000;
            while(fabs(r - l) > EPS) {
                db m1 = l + (r - l) / 3.0;
                db m2 = r - (r - l) / 3.0;
                if (f(m1) > f(m2)) {
                    l = m1;
                } else {
                    r = m2;
                }
            }
            xx = l;
        }
        for (int u: component) {
            ans[u] = xx * (db)val[u].first + (db) val[u].second;
        }
    }

    if (!possible) {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(7);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}