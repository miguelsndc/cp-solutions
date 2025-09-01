#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define ld long double
#define pii pair<int, int>

const ll INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;
const ld EPS = 1e-9;

class DSU {
  private:
    vector<int> parents;
    vector<int> sizes;

  public:
    DSU(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }

    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }

        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<array<ll, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        ll u, v, c; cin >> u >> v >> c;
        edges[i] = {--u ,--v, c};
    }

    int x = n - 1;
    vector<bool> mask(x, true);
    mask.resize(m, false);

    ll mst_cost = k;
    do {
        vector<array<ll, 3>> candidate;
        for(int i = 0; i < m; i++) {
            if (mask[i]) {
                candidate.push_back(edges[i]);
            }
        }

        int is_mst = true; ll cost = 0; int count = 0;
        vector<int> reachable(n);
        DSU dsu(n);
        for (const auto& [u, v, w]: candidate) {
            if (!dsu.unite(u, v)) { // cycle
                is_mst = false;
                break;
            }
            if (!reachable[u]) {
                reachable[u] = true;
                count++;
            } if (!reachable[v]) {
                reachable[v] = true;
                count++;
            }
            cost += w;
        }

        if (is_mst && count == n) {
            mst_cost = min((cost % k), mst_cost);
        }
    } while(prev_permutation(begin(mask), end(mask)));

    cout << mst_cost;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // setIO("");
    int tt = 1; // cin >> tt;
    for(int t = 1; t <= tt; t++) {
         // cout << "Case #" << t << ": ";
         solve();
    }
}