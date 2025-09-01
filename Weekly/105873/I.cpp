#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> k(maxn), g[maxn], subtree_sz(maxn), traversal, topics, ans, get_idx(maxn);

void traverse(int u, int p = -1) {
    traversal.push_back(u);
    get_idx[u] = traversal.size() - 1;
    subtree_sz[u] = 1;
    topics.push_back(k[u]);
    for (int v : g[u]) {
        if (v != p) {
            traverse(v, u);
            subtree_sz[u] += subtree_sz[v];
        }
    }
}

int len;
struct Query {
    int l, r, k, idx;
    bool operator<(const Query& other) const {
        int block_a = l / len, block_b = other.l / len;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

map<int, int> freq;
int get_ans(int k) {
    return freq[k];
}
void add(int idx) {
    freq[topics[idx]]++;
}
void remove(int idx) {
    freq[topics[idx]]--;
}

void mo(vector<Query> queries) {
    sort(all(queries));
    ans.assign(queries.size(), 0);
    int cur_l = 0, cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_ans(q.k);  // get answer
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    len = sqrt(n + .0);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    traverse(0);
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        queries[i] = {get_idx[x],
                      get_idx[x] + subtree_sz[x] - 1,
                      k,
                      i};
    }
    mo(queries);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}