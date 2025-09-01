#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> b(n);
        for (int &x: b) cin >> x;
        int ok = true, minn = 1e9+1;
        for (int x: b) {
            minn = min(x, minn);
            if (x >= 2 * minn) {
                ok = false;
            }
        }
        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
