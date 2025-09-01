#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5 + 5;

int n;
vector<int> a(maxn);
struct SegmentTree {
    vector<ll> tree;
    SegmentTree() {
        tree.resize(4 * (n + 1));
    }

    void update(int pos, int val, int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] += val;
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 1);
            }
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    ll query(int a, int b, int l = 1, int r = n, int v = 1) {
        if (b < l || a > r) return 0;
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        ll left = query(a, b, l, mid, v * 2);
        ll right = query(a, b, mid + 1, r, v * 2 + 1);
        return (left + right);
    }
};

void solve() {
    cin >> n;
    int q; cin >> q;
    SegmentTree seg;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        seg.update(i, x);
        if (i + 1 <= n) {
            seg.update(i + 1, -x);
        }
    }
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            ll a, b, u; cin >> a >> b >> u;
            seg.update(a, u);
            if (b + 1 <= n) {
                seg.update(b + 1, -u);
            }
        } else {
            int k; cin >> k;
            cout << seg.query(0, k) << '\n';
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