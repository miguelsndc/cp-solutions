#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

const int maxn = 1e5 + 5;
#define id pair<int,double>
#define di pair<double,int>
void solve() {
    int n, m; cin >> n >> m;
    vector<id> g[maxn];
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        double w = log(c)/log(7);
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<double> dist(maxn, INF);
    priority_queue<di, vector<di>, greater<di>> pq;
    dist[1] = log(1) / log(7);
    pq.push({dist[1], 1});
    while(!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (dist[u] != cost) continue;
        for (auto [v, w]: g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << setprecision(15) << fixed << dist[n] << '\n';
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