#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN = 1e5 + 1;
int parents[MAXN];
int sizes[MAXN];

void init() {
    for (int i = 0; i < MAXN; i++) {
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
    return true; // (condition met for component);
}

struct Edge {
    int from, to, cost;
    bool operator<(Edge &e) {return cost < e.cost; };
};

struct Query {
    int k, v, i;
    bool operator<(Query &q) {return k < q.k; };
};

void solve() {
    init();
    int n, q; cin >> n >> q;
    vector<Edge> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int k, v; cin >> k >> v;
        queries[i] = {k, v, i};
    }

    sort(rbegin(queries), rend(queries));
    sort(rbegin(edges), rend(edges));
    vector<int> solution(q); // solution[i] is answer for query i
    int idx = 0;
    for (auto [k, v, i] : queries) {
        while(idx < edges.size() && edges[idx].cost >= k) {
            if (unite(edges[idx].from, edges[idx].to)) {
                idx++;
            }
        }
        solution[i] = sizes[find(v)] - 1;
    }
    for (int i: solution) {
        cout << i << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   setIO("mootube");
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}