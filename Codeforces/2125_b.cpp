#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        ll a, b, k; cin >> a >> b >> k;
        ll g = __gcd(a, b);
        a /= g;
        b /= g;
        if (max(a, b) <= k) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}