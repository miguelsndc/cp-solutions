#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s; cin >> s;
    vector<int> pos(256);
    pos['a'] = 0;
    pos['t'] = 1;
    pos['c'] = 2;
    pos['o'] = 3;
    pos['d'] = 4;
    pos['e'] = 5;
    pos['r'] = 6;
    int n = s.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = pos[s[i]];
    }
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[i]) inv++;
        }
    }
    cout << inv << '\n';
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
