#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    
    ll ans = 1e9;
    for (int i = 0; i < n; i++) {
        int cur = a[i]; ll s = 0;
        for (int j = 0; j < n; j++) {
            s += abs(cur - a[j]);
        }
        ans = min(ans, s); 
    }
    cout << ans << '\n';
}
