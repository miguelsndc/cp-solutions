#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;
namespace rg = std::ranges;

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

void dfs(int u, const Dinic &dinic, vc<bool> &reached) {
    reached[u] = true;
    for (int id : dinic.adj[u]) {
        const Edge &e = dinic.edges[id];
        if (!reached[e.v] and e.cap > e.flow) {
            dfs(e.v, dinic, reached);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int src = 0, sink = n - 1;
    Dinic d(n, src, sink);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        auto [x, y] = minmax(a, b);
        d.add_edge(x, y, 1, 1);
    }
    ll flow = d.flow();
    vc<bool> reached(n);
    dfs(d.s, d, reached);
    vc<pair<int, int>> min_cut;
    for (int i = 0; i < d.m; i++) {
        const Edge &e = d.edges[i];
        if (reached[e.u] and !reached[e.v] and e.cap == e.flow) {
            min_cut.emplace_back(e.u, e.v);
        }
    }
    sort(min_cut.begin(), min_cut.end());

    cout << min_cut.size() << '\n';
    for (auto [x, y] : min_cut) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}