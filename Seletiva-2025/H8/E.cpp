#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e5 + 5;

struct Node {
    int mask = 0;
    int count = 0;
    Node (char l) {
        mask |= (1 << (l - 97));
        count = __builtin_popcount(mask);
    } 
    Node () {}
};

Node merge(Node a, Node b) {
    Node result;
    result.mask = a.mask | b.mask;
    result.count = __builtin_popcount(result.mask);
    return result;
}

vector<Node> tree; string a;

struct SegmentTree {
    SegmentTree() {
        tree.resize(4 * (n + 1));
    }

    void build(int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = Node(a[l]);
            return;
        } else {
            int mid = l + (r - l) / 2;
            build(l, mid, v * 2);
            build(mid + 1, r, v * 2 + 1);
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int pos, char val, int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = Node(val);
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 1);
            }
            tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    Node query(int a, int b, int l = 1, int r = n, int v = 1) {
        if (b < l || a > r) return Node();
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        Node left = query(a, b, l, mid, v * 2);
        Node right = query(a, b, mid + 1, r, v * 2 + 1);
        return merge(left, right);
    }
};

void solve() {
    string s; cin >> s;
    n = s.size() + 1;
    a += '0'; a += s; // 1-based
    int q; cin >> q;
    SegmentTree seg;
    seg.build();
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int pos; char val; cin >> pos >> val;
            seg.update(pos, val);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r).count << '\n';
        }
    }
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
