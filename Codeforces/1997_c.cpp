#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int w = 0;
    vector<int> v(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (w <= 0 and s[i] == '_') {
            s[i] = '(';
            w++;
        } else if (w > 0 and s[i] == '_') {
            s[i] = ')';
        } else {
            w += (s[i] == '(');
        }
        if (s[i] ==')') {
            ans += (i - v[w--]);
        } else {
            v[w] = i;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; cin >> T;
    while(T--) solve();
}
