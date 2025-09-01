#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

vector<int> tree(4 * maxn); int n;
void build(vector<int> &a, int l = 1, int r = n, int v = 1) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int mid = l + (r - l) / 2;
        build(a, l, mid, v * 2);
        build(a, mid + 1, r, v * 2 + 1);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
}

void update(int pos, int val, int l = 1, int r = n, int v = 1) {
    if (l == r) {
        tree[v] = val;
    } else {
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(pos, val, l, mid, v * 2);
        } else {
            update(pos, val, mid + 1, r, v * 2 + 1);
        }
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
}

i64 query(int a, int b, int l = 1, int r = n, int v = 1) {
    if (b < l || a > r) return (1e9 + 9);
    if (a <= l && r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    return min(query(a, b, l, mid, v * 2), query(a, b, mid + 1, r, v * 2 + 1));
}

void solve() {
    int q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(a);
    while(q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            update(a, b);
        } else {
            cout << query(a, b) << '\n';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}