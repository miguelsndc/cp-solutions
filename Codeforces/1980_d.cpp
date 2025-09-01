#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool valid (vector<int> &a, int &x) {
    int n = a.size();
    int prev = 0;
    for (int i = 1; i < n; i++) {
        int g = __gcd(a[i], a[i - 1]);
        if (g < prev) {
            x = i - 1;
            return false;
        }
        prev = g;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x:a) cin >> x;
    int x = 0, y = -1;
    if (valid(a, x)) {
        cout << "YES\n";
        return;
    }
    vector<int> b = a, c = a, d = a;
    b.erase(b.begin() + x), c.erase(c.begin() + x + 1);

    if (valid(b, y) or valid(c, y)) {
        cout << "YES\n";
        return;
    }

    if (x > 0) {
        d.erase(d.begin() + (x - 1));
        if (valid(d, x)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  cin >> T;
    while(T--) solve();
}