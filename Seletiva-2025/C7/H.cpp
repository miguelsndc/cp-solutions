#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[100005];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    vector<int> vis(n);
    ll result = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            queue<int> q;
            ll sz = 1;
            q.push(i);
            vis[i] = true;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        sz++;
                        q.push(v);
                    }
                }
            }
            result *= sz;
            result %= MOD;
        }
    }
    cout << result;
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