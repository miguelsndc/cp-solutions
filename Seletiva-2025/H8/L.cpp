#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 inf = 1E18;
const int maxn = 1e6 + 5;

struct node {
    int maxlen, open, closed;
};

int n;
vector<char> a(maxn);
node tree[6 * maxn];

node join(node a, node b) {
    int t = min(a.open, b.closed);
    node joined;
    joined.maxlen = a.maxlen + b.maxlen + t;
    joined.open = a.open + b.open - t;
    joined.closed = a.closed + b.closed - t;
    return joined;
}

void build(int l = 1, int r = n, int v = 1) {
    if (l == r) {
        if (a[l] == '(') tree[v] = {0, 1, 0};
        else tree[v] = {0, 0, 1};
    } else {
        int mid = l + (r - l) / 2;
        build(l, mid, v * 2);
        build(mid + 1, r, v * 2 + 1);
        tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
    }
}

node query(int a, int b, int l = 1, int r = n, int v = 1) {
    if (b < l || a > r) return {0, 0, 0};
    if (a <= l && r <= b) return tree[v];
    int mid = l + (r - l) / 2;
    node left = query(a, b, l, mid, v * 2);
    node right = query(a, b, mid + 1, r, v * 2 + 1);
    return join(left, right);
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++) a[i] = s[i - 1];
    build();
    int m; cin >> m;
    while(m--) {
        int l, r; cin >> l >> r;
        int ans =  query(l, r).maxlen * 2;
        cout << ans  << '\n';
    }
}