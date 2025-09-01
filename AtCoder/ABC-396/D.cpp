#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;

struct Node {
    u64 u, acc_xor;
    u64 visited = 0;
    Node(u64 _u, u64 _x): u(_u), acc_xor(_x) {}
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<pair<u64, u64>> g[20];
    for(int i = 0; i < m; i++) {
        u64 u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    queue<Node> q;
    Node start = Node(1, 0);
    start.visited |= (1 << 1);
    q.push(start);
    u64 min_xor = UINT64_MAX;
    while(!q.empty()) {
        int u = q.front().u;
        u64 vis = q.front().visited;
        u64 acc_xor = q.front().acc_xor;
        q.pop();

        if (u == n) {
            min_xor = min(min_xor, acc_xor);
            continue;
        }

        for (const auto &[v, w]: g[u]) {
            if (vis & (1 << v)) continue;
            Node new_v = Node(v, (acc_xor ^ w));
            new_v.visited |= (vis | (1 << v));
            q.push(new_v);
        }
    }
    cout << min_xor;
}