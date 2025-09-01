#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 5e5 + 5;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int weight, cnt, left, right, val;
    node (int v): cnt(1), weight(rng()), left(-1), right(-1), val(v) {}
};

vector<node> tree;

int cnt(int i) { return i == -1 ? 0 : tree[i].cnt; }
int val(int i) { return i == -1 ? 0 : tree[i].val; }
void update_cnt(int i) { if (i != -1) tree[i].cnt = 1 + cnt(tree[i].left) + cnt(tree[i].right); }

void split(int u, int k, int &l, int &r) {
    if (u == -1) { l = r = -1; return; } 
    if (cnt(tree[u].left) < k) {
        split(tree[u].right, k - cnt(tree[u].left) - 1, tree[u].right, r);
        l = u;
    } else {
        split(tree[u].left, k, l, tree[u].left);
        r = u;
    }
    update_cnt(u);
}

void merge(int l, int r, int &u) {
    if (l == -1 || r == -1) { u = (l == -1 ? r : l); return; }
    if (tree[l].weight > tree[r].weight) {
        merge(tree[l].right, r, tree[l].right);
        u = l;
    } else {
        merge(l, tree[r].left, tree[r].left);
        u = r;
    }
    update_cnt(u);
}

void solve() {
    int n; 
    cin >> n;
    
    int rt = -1;
    for (int i = 1; i <= n; i++) {
        tree.push_back(node(i));
        merge(rt, tree.size() - 1, rt);
    }

    int queries = n; // Use a separate counter for queries
    while (queries--) {
        int a, b; 
        cin >> a >> b;
        if (b <= a) continue;
        
        --a, --b; // Convert to 0-based index
        
        int size = min(n - b, b - a);
        int halves[2], h1p1[2], h1p2[2], h2p2[2];

        // Split into 3 parts: [0, a-1], [a, b], [b+1, n-1]
        split(rt, b, halves[0], halves[1]);
        split(halves[0], a, h1p1[0], h1p1[1]);
        split(h1p1[1], size, h1p2[0], h1p2[1]);
        split(halves[1], size, h2p2[0], h2p2[1]);

        int tmp1, tmp2, tmp3, tmp4;
        merge(h1p2[0], h2p2[1], tmp1);
        merge(h1p2[1], tmp1, tmp2);
        merge(h2p2[0], tmp2, tmp3);
        merge(h1p1[0], tmp3, tmp4);
        rt = tmp4;
    }

    // Output the final array
    for (int i = 0; i < n; i++) {
        int l;
        split(rt, 1, l, rt);
        cout << val(l) << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}
