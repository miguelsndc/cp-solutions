#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int mod = 1e9 + 7;
ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
vector<ll> FWHT(char oper, vector<ll> a, const bool inv = false) {
    int n = (int)a.size();
    for (int len = 1; len < n; len += len) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                auto u = a[i + j], v = a[i + j + len];
                if (oper == '^') {
                    a[i + j] = (u + v) ;
                    a[i + j + len] = u - v;
                }
                if (oper == '|') {
                    if (!inv) {
                        a[i + j + len] = (u + v) % mod;
                    } else {
                        a[i + j + len] = (v - u + mod) % mod;
                    }
                }
                if (oper == '&') {
                    if (!inv) {
                        a[i + j] = (u + v) % mod;
                    } else {
                        a[i + j] = (u - v + mod) % mod;
                    }
                }
            }
        }
    }
    if (oper == '^' && inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
    return a;
}

vector<ll> multiply(char oper, vector<ll> a, vector<ll> b) {
    int n = 1;
    while (n < (int)max(a.size(), b.size())) {
        n <<= 1;
    }
    vector<ll> ans(n);
    while (a.size() < ans.size()) a.push_back(0);
    while (b.size() < ans.size()) b.push_back(0);
    a = FWHT(oper, a);
    b = FWHT(oper, b);
    for (int i = 0; i < n; i++) {
        ans[i] = a[i] * b[i];
    }
    ans = FWHT(oper, ans, true);
    return ans;
}
void solve() {
    int N; cin >> N;
    vector tree(N, vector<pii>());
    for (int j = 0; j < N - 1; j++) {
        int u, v, w; cin >> u >> v >> w;
        tree[--u].push_back({--v, w});
        tree[v].push_back({u, w});
    }
    vector<int> dist(N);

    auto dfs = [&](auto && self, int u, int p) -> void {
        for (auto &[v, w]: tree[u]) {
            if (v != p) {
                dist[v] = (dist[u] + w) % 100000;
                self(self, v, u);
            } 
        }
    };
    dfs(dfs, 0, -1);
    int n = 1e5, sz = 1;
    while(sz < n) sz <<= 1;
    vector<ll> freq(sz);
    for (int i = 0; i < N; i++) {
        freq[dist[i]]++;
    }

    vector<ll> ans =  multiply('^', freq, freq);

    vector<int> res;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > 0) {
            res.push_back(i);
        }
    }

    cout << res.size() << '\n';
    for (int x: res) cout << x << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}