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

const int MAXN = 1001;

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

void solve() {
    int n; cin >> n;
    vector<ii> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        edges[i] = {a, b};
    }

    init(n + 1);
    vector<pair<int, int>> removed;
    for (auto e: edges) {
        if (!unite(e.first, e.second)) {
            removed.push_back(e);
        }
    }

    vector<int> par;
    for (int i = 1; i <= n; i++) {
        find(i);
        par.push_back(parents[i]);
    }
    sort(begin(par), end(par));

    par.resize(unique(begin(par), end(par)) - begin(par));

    vector<ii> rebuilt;
    for (int i = 0; i < par.size() - 1; i++) {
        rebuilt.push_back({par[i], par[i + 1]});
    }

    cout << par.size() - 1 << '\n';

    for (int i = 0; i < rebuilt.size(); i++) {
        cout << removed[i].first << ' ' << removed[i].second << ' ' <<
                rebuilt[i].first << ' ' << rebuilt[i].second << '\n';
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