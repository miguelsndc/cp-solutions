#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

class DSU {
  private:
    map<string, string> parents;
    map<string, int> sizes;

  public:
    void make_set(string x) {
        parents[x] = x;
        sizes[x] = 1;
    }

    string find(string x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(string x, string y) {
        string x_root = find(x);
        string y_root = find(y);
        if (x_root == y_root) { return false; }

        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    int size_of(string x) {
        return sizes[find(x)];
    }

    bool connected(string x, string y) { return find(x) == find(y); }
};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        DSU dsu;
        int n; cin >> n;
        map<string, bool> seen;
        
        for (int i = 0; i < n; i++) {
            string a, b; cin >> a >> b;

            if (seen.find(a) == seen.end()) {
                dsu.make_set(a);
                seen[a] = true;
            }
            if (seen.find(b) == seen.end()) {
                dsu.make_set(b);
                seen[b] = true;
            }

            if (!dsu.connected(a, b)) {
                dsu.unite(a, b);
                cout << dsu.size_of(a);
            } else {
                cout << dsu.size_of(a);
            }
            
            cout << '\n';
        }
    }
}