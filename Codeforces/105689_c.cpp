#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int &x:a)cin>>x;
    int ans = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) <= d) {
            cur++;
        } else {
            cur = 1;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
