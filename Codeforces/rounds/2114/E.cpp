#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define pii pair<int, int>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template<typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p+strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',')+1 : p+strlen(p)), ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 25 + 5;

vector<ll> a, val;       
vector<vector<int>> adj;  

void dfs(int u, int p, ll mintp, ll maxtp) {
    ll tu = max(a[u], a[u] - mintp);
    val[u] = tu;
    ll min_t_u = min(a[u], a[u] - maxtp);
    ll max_t_u = tu;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, min_t_u, max_t_u);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    val.assign(n, 0);
    dfs(0, -1, inf, -inf);
    for (int i = 0; i < n; ++i) {
        cout << val[i] << " ";
    }
    cout << "\n";
}

int main() 
{
    fast;
    int tt = 1;  cin >> tt;
    while(tt--) solve();
}