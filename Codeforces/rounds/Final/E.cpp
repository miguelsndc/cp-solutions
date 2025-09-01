#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int inv100 = 570000004;

i64 fexp(i64 a, i64 b){
    i64 ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

i64 inv(i64 a){ 
    return fexp(a, MOD - 2);
}
int n; 
vector<i64> a(MAXN); 

struct SegmentTree {
    vector<pair<i64, i64>> tree;
    SegmentTree() {
        tree.resize(4 * (n + 1));
    }

    pair<i64, i64> join(pair<i64, i64> a, pair<i64, i64> b) {
        return {(a.first * b.first) % MOD, (a.second + b.second) % MOD};
    }

    // O(n)
    void build(int l = 1, int r = n, int v = 1) {
        if (l == r) {
            i64 qi = (100 - a[l]) * inv100 % MOD;
            i64 ti = a[l] * inv(100 - a[l]) % MOD;
            tree[v] = {qi, ti};
        } else {
            int mid = l + (r - l) / 2;
            build(l, mid, v * 2);
            build(mid + 1, r, v * 2 + 1);
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    // O(log(n))
    void update(int pos, i64 val, int l = 1, int r = n, int v = 1) {
        if (l == r) {
            i64 qi = (100 - val) * inv100 % MOD;
            i64 ti = val * inv(100 - val) % MOD;
            tree[v] = {qi, ti};
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

    // O(log(n))
    pair<i64, i64> query(int a, int b, int l = 1, int r = n, int v = 1) {
        if (b < l || a > r) return {1, 0};
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        auto left = query(a, b, l, mid, v * 2);
        auto right = query(a, b, mid + 1, r, v * 2 + 1);
        return join(left, right);
    }
};


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    SegmentTree seg;
    seg.build();
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, p; cin >> x >> p;
            seg.update(x,p);
        } else {
            int x; cin >> x;
            if (x == n)  {
                cout << 1 << '\n';
            }
            auto [q, s] = seg.query(x + 1, n);
            cout << (q * (s + 1)) % MOD << '\n';
        }
    }
}