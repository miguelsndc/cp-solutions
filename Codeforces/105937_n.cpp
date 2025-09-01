#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int sz;
vc<int> tree, a;

void build(int l = 0, int r = sz - 1, int v = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

int query(int a, int b, int l = 0, int r = sz - 1, int v = 0) {
    if (a > r || b < l) return 1e9;
    if (l >= a and r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    int left = query(a, b, l, mid, v * 2 + 1);
    int right = query(a, b, mid + 1, r, v * 2 + 2);
    return min(left, right);
}

void update(int pos, int val, int l = 0, int r = sz - 1, int v = 0) {
    tree[v] = val;
    if (l == r) {
        return;
    } else {
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(pos, val, l, mid, v * 2 + 1);
        } else {
            update(pos, val, mid + 1, r, v * 2 + 2);
        }
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

void solve() {
    int n;
    cin >> n;
    sz = n;
    a.assign(n, 0);
    tree.assign(5 * n, 1e9);
    vc<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    build();
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        if (l == 0 and r == n - 1) {
            cout << "peace\n";
            continue;
        }

        int mex = n - 1;
        if (r == n - 1) {
            mex = min(mex, query(0, l - 1));
        } else if (l == 0) {
            mex = min(mex, query(r + 1, n - 1));
        } else {
            int left = query(0, l - 1);
            int right = query(r + 1, n - 1);
            mex = min(mex, min(left, right));
        }

        if (mex >= n - 1) {
            cout << "peace\n";
            continue;
        }

        update(pos[mex], mex + 1);
        update(pos[mex + 1], mex);

        swap(pos[mex], pos[mex + 1]);

        cout << mex + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}