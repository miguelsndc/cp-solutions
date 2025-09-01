#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

vector<i64> bit(maxn), arr(maxn);

void add(int pos, int val) {
    for (int i = pos + 1; i < maxn; i += (i & (-i))) bit[i] += val;
}

void pset(int pos, int val) {
    int delta = val - arr[pos]; arr[pos] = val; 
    add(pos, delta);
}

i64 query(int pos) {
    i64 sum = 0;
    for (int i = pos + 1; i > 0; i -= (i & (-i))) sum += bit[i];
    return sum;
}

void solve() {
    int n, q; cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        add(i, arr[i]);
    }
    
    while(q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            pset(a - 1, b);
        } else {
            cout << query(b - 1) - query(a - 2) << '\n';
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