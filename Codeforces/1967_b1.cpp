#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int n, m; cin >> n >> m;
    ll count = 0;
    for (int d = 1; d <= m; d++) {
        count += ((n/d)+1)/d;
    }
    cout << count -1<< '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}