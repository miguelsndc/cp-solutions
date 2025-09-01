#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

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

    int size_of(int x) { return sizes[find(x)]; }

    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    int maxcomp = 1, comps = n;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; --u, --v;
        if (dsu.unite(u, v)) { // united fine without cycles
            comps--;
        }
        maxcomp = max(maxcomp, dsu.size_of(u));
        cout << comps << ' ' << maxcomp << '\n';
    } 
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}