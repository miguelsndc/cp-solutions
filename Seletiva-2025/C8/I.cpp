#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int power(int b, int p, int m) {
    long long x = 1;
    int power = b % m;
    int k = log2(p);
    for (int i = 0; i <= k; i++) {
       int a = (p >> i) & 1;
       if (a == 1)
           x = (x * power) % m;
       power = (power * power) % m;
   }
    return x;
}

const int MAXN = 1e5 + 5;
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
    return true; // (some condition met for component);
}

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> edges(n - 1);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        edges[i - 1] = {w, u , v};
    }
    init();
    ll cnt = 0;
    sort(begin(edges), end(edges));
    for (const auto &[w, u, v]: edges) {
        cnt += 1LL * w * sizes[find(u)] * sizes[find(v)];
        unite(u, v);
    }
    cout << cnt;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}