#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    string s;
    while(n) {
         int k = n % 10;
         s += char(k + '0');
         n /= 10;
    }
    while(s.size() < 4) {
        s += "0";
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
