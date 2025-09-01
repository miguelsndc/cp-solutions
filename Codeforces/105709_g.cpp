#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct FenwickTree {
    int sz;
    vector<ll> bit, arr;

    FenwickTree(int n): sz(n + 1) {
        bit.assign(sz, 0);
        arr.assign(sz, 0);
    }

    // O(log(n))
    void add(int pos, int val) {
        for (int i = pos + 1; i < sz; i += (i & (-i))) bit[i] += val;
    }
    // O(log(n))
    void pset(int pos, int val) {
        int delta = val - arr[pos];
        arr[pos] = val;
        add(pos, delta);
    }

    // O(log(n))
    ll query(int pos) {
        ll sum = 0;
        for (int i = pos + 1; i > 0; i -= (i & (-i))) sum += bit[i];
        return sum;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    map<int,int> coords;
    for (int i = 0; i < n; i++) {
        coords[b[i]] = i;
    }
    FenwickTree fwt(n + 1);
    ll inv = 0;
    for (int i = 0; i < n; i++) {
        inv += fwt.query(n) - fwt.query(coords[a[i]]);
        fwt.add(coords[a[i]], 1);
    }
    cout << 1 - (inv % 2) << '\n';
}
