#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';

typedef pair<ll, int> pli;

const ll INF = 1e18;

struct Edge {
    int to;
    ll c, e;
};

vector<Edge> edges;
vector<vector<int>> adj;

void addEdge(int from, int to, ll c, ll e) {
    edges.push_back({to, c, e});
    adj[from].push_back(edges.size() - 1);
}

vector<ll> dijkstra(int start, function<ll(const Edge&)> getWeight) {
    int n = adj.size() - 1;
    vector<ll> dist(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        ll cost = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (cost > dist[u]) continue;
        for (int idx : adj[u]) {
            const Edge& edge = edges[idx];
            int v = edge.to;
            ll next_cost = cost + getWeight(edge);
            if (next_cost < dist[v]) {
                dist[v] = next_cost;
                pq.push({next_cost, v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    adj.resize(n + 1); 

    fori(m) {
        int u, v, c, e;
        cin >> u >> v >> c >> e;
        addEdge(v, u, c, e); 
    }

    vi entrances(a);
    fori(a) cin >> entrances[i];

    fori(b) {
        int t;
        cin >> t;
        addEdge(0, t, 0, 0); 
    }
    auto dist_c = dijkstra(0, [](const Edge& e) { return e.c; });
    auto dist_e = dijkstra(0, [](const Edge& e) { return e.e; });

    vector<ll> chicken_times, egg_times;
    fori(a) {
        int node = entrances[i];
        if (dist_c[node] < INF) {
            chicken_times.push_back(dist_c[node]);
            egg_times.push_back(dist_e[node]);
        }
    }

    int r = chicken_times.size();
    ll sum_less = 0, sum_greater = 0;

    if (r > 0) {
        vector<ll> sorted_egg = egg_times;
        sort(sorted_egg.begin(), sorted_egg.end());
        for (ll ct : chicken_times) {
            auto it = upper_bound(sorted_egg.begin(), sorted_egg.end(), ct);
            sum_less += sorted_egg.end() - it;
        }

        vector<ll> sorted_chicken = chicken_times;
        sort(sorted_chicken.begin(), sorted_chicken.end());
        for (ll et : egg_times) {
            auto it = upper_bound(sorted_chicken.begin(), sorted_chicken.end(), et);
            sum_greater += sorted_chicken.end() - it;
        }
    }

    ll count_chicken = sum_less + (ll)r * (a - r);
    ll count_egg = sum_greater + (ll)(a - r) * r;

    if (count_chicken > count_egg) writeln("chicken")
    else if (count_chicken < count_egg) writeln("egg")
    else writeln("tie")

    return 0;
}