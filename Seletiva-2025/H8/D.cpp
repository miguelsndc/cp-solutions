#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 2e5 + 5;
vector<double> tree, a(maxn);

struct SegmentTree {
    SegmentTree() {
        tree.resize(4 * (n + 1));
    }

    double join(double a, double b) {
        return a + b;
    }

    void build(int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = a[l];
            return;
        } else {
            int mid = l + (r - l) / 2;
            build(l, mid, v * 2);
            build(mid + 1, r, v * 2 + 1);
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int pos, double val, int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = val;
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 1);
            }
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    double query(int a, int b, int l = 1, int r = n, int v = 1) {
        if (b < l || a > r) return 0;
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        double left = query(a, b, l, mid, v * 2);
        double right = query(a, b, mid + 1, r, v * 2 + 1);
        return join(left, right);
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x; cin >> x;
        a[i] = x;
    }
    int q; cin >> q;
    SegmentTree seg;
    seg.build();
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int pos; double val; cin >> pos >> val;
            seg.update(pos, val);
        } else {
            int a, b; cin >> a>>b;
            double r = seg.query(a, b);
            cout << setprecision(7) << fixed << (r / ((b - a + 1) * 1.0))<< '\n';
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