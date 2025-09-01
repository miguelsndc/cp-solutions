#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e6;

using std::vector, std::cin, std::ios_base;

vector<int> enter(maxn), leave(maxn);

vector<int> g[maxn];

struct FenwickTree {
    vector<i64> bit, arr;

    FenwickTree(int size) {
        bit.assign(size + 1, 0);
        arr.assign(size + 1, 0);
    }
    void set(int pos, int val) {
        add(pos, val - arr[pos]);
    }

    void add(int pos, int val) {
        arr[pos] += val;
        ++pos;
        for (; pos < maxn; pos += (pos & (-pos))) bit[pos] += val;
    }
    i64 query(int pos) {
        ++pos;
        i64 sum = 0;
        for (; pos > 0; pos -= (pos & (-pos))) sum += bit[pos];
        return sum;
    }
};

int timer = 0;
void euler_tour(int u = 0, int p = -1) {
    enter[u] = timer++;
    for (int v : g[u]) {
        if (v != p) euler_tour(v, u);
    }
    leave[u] = timer;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    for (int& v : values) cin >> v;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    euler_tour(0);

    FenwickTree bit(maxn);

    for (int i = 0; i < n; i++) {
        bit.set(enter[i], values[i]);
    }

    for (; q > 0; q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int node, val;
            cin >> node >> val;
            bit.set(enter[--node], val);
        } else {
            int node;
            cin >> node;
            i64 end_sum = bit.query(leave[--node] - 1);
            i64 start_sum = enter[node] == 0 ? 0 : bit.query(enter[node] - 1);
            std::cout << end_sum - start_sum << '\n';
        }
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