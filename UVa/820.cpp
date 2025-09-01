#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

// namespace rg = std::ranges;

struct Edge {
    int u, v;
    ll cap, flow = 0;
    Edge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
    vc<Edge> edges;
    vc<vc<int>> adj;
    int n, s, t, m = 0;
    vc<int> lvl, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, ll cap, ll other = 0) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, other);
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap == edges[id].flow) continue;
                if (lvl[edges[id].v] != -1) continue;
                lvl[edges[id].v] = lvl[u] + 1;
                q.push(edges[id].v);
            }
        }
        return lvl[t] != -1;
    }

    ll dfs(int u, ll pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;
        for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (lvl[v] != lvl[u] + 1) continue;
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (1) {
            fill(lvl.begin(), lvl.end(), -1);
            lvl[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll p = dfs(s, inf)) {
                f += p;
            }
        }
        return f;
    }
};

int cnt = 1;
void solve(int n) {
    int s, t, c;
    cin >> s >> t >> c;
    --s, --t;
    Dinic d(n, s, t);
    for (int i = 0; i < c; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        d.add_edge(u, v, w, w);
    }
    ll mf = d.flow();
    cout << "Network " << cnt++ << "\n";
    cout << "The bandwidth is " << mf << ".\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while ((cin >> n) and (n > 0)) {
        solve(n);
    }
}