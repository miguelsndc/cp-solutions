#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n; const int maxn = 3e5 + 5;
vector<int> tree[4 * maxn], a(maxn);
void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v].push_back(a[l]);
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        int i = 0, j = 0;
        while (i < tree[v * 2 + 1].size() and j < tree[v * 2 + 2].size()) {
            if (tree[v * 2 + 1][i] < tree[v * 2 + 2][j])
                tree[v].push_back(tree[v * 2 + 1][i++]);
            else
                tree[v].push_back(tree[v * 2 + 2][j++]);
        }
        while (i < tree[v * 2 + 1].size())
            tree[v].push_back(tree[v * 2 + 1][i++]);
        while (j < tree[v * 2 + 2].size())
            tree[v].push_back(tree[v * 2 + 2][j++]);
    }
}

int query(int a, int b, int k, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return 0;
    if (l >= a and r <= b) {
        return (tree[v].size() - (lower_bound(tree[v].begin(), tree[v].end(), k) - begin(tree[v])));
    }
    int m = (l + r) / 2;
    int half1 = query(a, b, k, l, m, v * 2 + 1);
    int half2 = query(a, b, k, m + 1, r, v * 2 + 2);
    return half1 + half2;
}
void solve() {
    int y, m; cin >> y >> m;
    n = y;
    for (int i = 0; i < y; i++) {
        cin >> a[i];
    }
    build();
    while(m--) {
        int j, pos, x; cin >> j >> pos >> x;
        --j;
        if (pos <= a[j]) {
            cout << 0 << '\n';
            continue;
        }
        int l = min(j + 1, n - 1);
        int r = min(n - 1, j + x);
        int ans = query(l, r, pos);
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}