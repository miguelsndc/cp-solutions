#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<ll, ll>

struct Edge
{
    int from, to, cost;
    bool operator<(Edge& e) {return cost < e.cost; }
};


const int MAXN = 1e4 + 1;

int parents[MAXN];
int sizes[MAXN];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        sizes[i] = 1;
    }
}

int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

bool unite(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    if (x_root == y_root) { return false; }
    if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
    sizes[x_root] += sizes[y_root];
    parents[y_root] = x_root;
    return true; // (some condition met for component);
}

ii solve() {
    int n, m, a; cin >> n >> m >> a;
    vector<Edge> edges(m);
    init(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    sort(begin(edges), end(edges));
    ll road_cost = 0;
    for (auto e: edges) {
        if (unite(e.from, e.to)) {
            road_cost += e.cost;
        }
    }

    set<int> s;
    for (int i = 1; i <= n; i++) {
        find(i);
        s.insert(parents[i]);
    }

    road_cost += a * s.size();
    return {road_cost, s.size()};
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        ii p = solve();
        cout << "Case #" << i << ": " << p.first << ' ' << p.second << '\n';
    }
}