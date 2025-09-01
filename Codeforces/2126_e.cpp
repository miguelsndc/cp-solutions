#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    int p[n], s[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    ll g = p[n - 1];
    if (p[n - 1] != s[0]) {
        cout << "NO\n";
        return;
    }

    bool ok = true;
    for (int i = 1; i < n; i++) {
        ok &= (p[i - 1] % p[i]) == 0;
    }
    for (int i = n - 2; i >= 0; i--) {
        ok &= (s[i + 1] % s[i]) == 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        ok &= (__gcd(p[i], s[i])) == g;
    }

    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  cin >> T;
    while(T--) solve();
}