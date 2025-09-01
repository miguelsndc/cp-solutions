#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

const int maxn = 1e5 + 5;

array<vector<pair<int, int>>, maxn> g;
array<int, maxn> dist;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    queue<int> q;
    array<bool, maxn> visited;
    dist.fill(0);
    visited.fill(0);
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w]: g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] ^ w;
                q.push(v);
            }
        }
    }

    i64 s = 0;
    for (int i = 0; i < 30; i++) {
        array<i64, 2> bits = {0, 0};
        for (int j = 1; j <= n; j++) {
            if (dist[j] & (1 << i)) bits[1]++;
            else bits[0]++;
        }
        i64 c = bits[0] * bits[1];
        s += (c << i);
    }
    cout << s;
}