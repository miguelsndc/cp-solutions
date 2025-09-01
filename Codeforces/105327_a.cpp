#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    k -= (n - 1);
    cout << k / n << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}