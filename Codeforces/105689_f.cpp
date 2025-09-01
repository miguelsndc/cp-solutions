#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
vector<int> tree; int n;
void build(vector<int> &a, int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(a, l, mid, v * 2 + 1);
        build(a, mid + 1, r, v * 2 + 2);
        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}
void update(int pos, int val, int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v] = val;
        return;
    } else {
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(pos, val, l, mid, v * 2 + 1);
        } else {
            update(pos, val, mid + 1, r, v * 2 + 2);
        }
        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    tree.assign(4 * n, 0);
    vector<int> a(n);
    for (int &x:a)cin >>x;
    build(a);
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int p; cin >> p; --p;
            cout << tree[0] - a[p] << '\n';
        } else {
            int p, x; cin >> p >> x;
            a[--p] = x;
            update(p, x);
        }
    }
}
