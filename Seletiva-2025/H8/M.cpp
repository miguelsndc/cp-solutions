#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;
const int maxn = 1e5 + 5;

int n;
int a[maxn], tree[8 * maxn]; pair<int, int> b[maxn]; // 1-based

void build(int l = 1, int r = n, int v = 1) {
    if (l == r) {
        tree[v] = a[l];
        return;
    } else {
        int mid = l + (r - l) / 2;
        build(l, mid, v * 2);
        build(mid + 1, r, v * 2 + 1);
        tree[v] = __gcd(tree[v * 2], tree[v * 2 + 1]);
    }
}

i64 query(int a, int b, int l = 1, int r = n, int v = 1) {
    if (b < l || a > r) return (0);
    if (a <= l && r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    i64 left = query(a, b, l, mid, v * 2);
    i64 right = query(a, b, mid + 1, r, v * 2 + 1);
    return __gcd(left, right);
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    for (int i = 1; i <= n; i++) { b[i] = {a[i], i}; }
    sort(b + 1, b + n + 1);
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        int m = query(l, r);
        int f = lower_bound(b + 1, b + n + 1, make_pair(m, l)) - (b + 1);
        int to = lower_bound(b + 1, b + n + 1, make_pair(m, r + 1)) - (b + 1);
        cout << (r - l + 1) - (to - f) << '\n';
    }
}