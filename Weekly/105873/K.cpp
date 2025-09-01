#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char *names, T... args) {
    const char *p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 205;

struct Edge {
    ll to, cap, rev;
};

vector<Edge> g[maxn];
int level[maxn], iter[maxn];

void add_edge(int from, int to, ll cap) {
    g[from].push_back({to, cap, (int)g[to].size()});
    g[to].push_back({from, 0, (int)g[from].size() - 1});
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : g[u]) {
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
}

ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    for (int &i = iter[u]; i < g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap > 0 && level[u] < level[e.to]) {
            ll d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t) {
    ll flow = 0;
    while (true) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        ll f;
        while ((f = dfs(s, t, inf)) > 0) {
            flow += f;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        g[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(v, u, inf);
    }
    int s = 0, t = n + 1;
    g[s].clear();
    g[t].clear();
    ll ps = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] > 0) {
            add_edge(s, i, d[i]);
            ps += d[i];
        } else if (d[i] < 0) {
            add_edge(i, t, -d[i]);
        }
    }
    ll mf = max_flow(s, t);
    cout << ps - mf << '\n';
    return 0;
}