#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        if (n == 1 or m == 1 or (n == 2 and m == 2)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
