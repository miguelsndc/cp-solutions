#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x:a) cin >> x;

    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) 
        pre[i + 1] = __gcd(pre[i], a[i]);
    for (int i = n - 1; i >= 0; i--) 
        suf[i] = __gcd(suf[i + 1], a[i]);

    int mx = 0;
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            mx = max(mx, __gcd(pre[i - 1], suf[i]));
        }
    }
    cout << mx << '\n';
}
