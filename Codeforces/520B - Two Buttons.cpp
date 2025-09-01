#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<ll, ll>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 1e4 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> dist(maxn, 1e9 + 9);
    int n, m; cin >> n >> m;
    dist[n] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({n, 0});
    while(!q.empty()) {
        auto [u, cost] = q.top();
        q.pop();
        if (dist[u] != cost) continue;
        ll nu = u - 1;
        if (nu > 0 && dist[nu] > dist[u] + 1) {
            dist[nu] = dist[u] + 1;
            q.push({nu, dist[nu]});
        }
        nu = u << 1;
        if (nu < maxn && dist[nu] > dist[u] + 1) {
            dist[nu] = dist[u] + 1;
            q.push({nu, dist[nu]});
        }
    }
    cout << dist[m];
}