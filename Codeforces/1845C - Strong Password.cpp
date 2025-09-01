#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s; cin >> s;
    int m; cin >> m;
    string l, r; cin >> l >> r;

    int p = 0;
    for (int i = 0; i < m; i++) {
        int q = p;
        for (char x = l[i]; x <= r[i]; x++) {
            if (s.find(x, p) == -1) {
                cout << "YES\n";
                return;
            }
            q = max(q, int(s.find(x, p)) + 1);
        }
        p = q;
    }
    cout << "NO\n";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) {
        solve();
    }
}