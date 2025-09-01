#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i; cin >> i;
    vector<int> v(4); v[i] = 1;
    for (int i = 0; i < 3; i++) {
        int l, r; cin >> l >> r;
        swap(v[l], v[r]);
    }
    for (int i = 1; i <= 3; i++) {
        if (v[i]) cout << i;
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