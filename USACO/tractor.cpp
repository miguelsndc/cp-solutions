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

void init();
bool unite(int x, int y);

struct Node {
    int y, x;
};

struct Edge {
    Node from, to;
    int cost;
    bool operator<(const Edge &e) { return cost < e.cost; }
};

int dy[] {0, 0, 1, -1};
int dx[] {1, -1, 0, 0};

int n;
const int MAXN = 500;

int parents[MAXN * MAXN];
int sizes[MAXN * MAXN];
int grid[MAXN][MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    init();
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int u = 0; u < 4; u++) {
                int di = i + dy[u];
                int dj = j + dx[u];
                if (di < 0 || di >= n || dj < 0 || dj >= n) continue;

                Node from = {i, j};
                Node to = {di, dj};

                if (grid[i][j] >= grid[di][dj]) {
                    Edge e = {from, to, grid[i][j] - grid[di][dj]};
                    edges.push_back(e);
                }
            }
        }
    }

    sort(begin(edges), end(edges));
    for (const auto&[from, to, cost]: edges) {
        if (unite(from.y * n + from.x, to.y * n + to.x)) {
            cout << cost;
            return;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef BATATA_DOCE_FRITA
        setIO("tractor");
    #endif
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}

void init() {
    for (int i = 0; i < n * n; i++) {
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
    return sizes[x_root] >= (n * n + 1) / 2;
}