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

struct Edge {
    int a, b, cost;
    bool operator<(Edge &e) {return cost < e.cost;}
};

const int MAXN = 2000;
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

int teams[MAXN];
void solve() {
    int n; cin >> n;
    init(n);
    vector<Edge> edges;
    for (int i = 0; i < n; i++) cin >> teams[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, j, (teams[i] ^ teams[j])});
        }
    }
    ll cost = 0, count = 0;
    sort(rbegin(edges), rend(edges));
    for (auto e: edges) {
        if (unite(e.a, e.b)) {
            cost += e.cost;
            count++;
            if (count == n - 1) break;
        }
    }
    cout << cost;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("superbull");
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}