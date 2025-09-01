#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {	
    int n; cin >> n;
    ll fib[50]= {0};
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n + 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; // cin >> T;
    while(T--) solve();
}