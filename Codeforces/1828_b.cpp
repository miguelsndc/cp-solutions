#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pos(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = __gcd(abs(a[i] - pos[a[i]]), ans);
    }
    cout << max(ans, 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1; cin >> T;
    while(T--) solve();
}