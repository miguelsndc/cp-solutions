#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    string a, b;
    cin >> a >> b;
    map<string, int> mp;

    if (a[0] == b[0]) {
        cout << "YES\n";
        cout << a[0] << "*\n";
        return;
    } else if (a.back() == b.back()) {
        cout << "YES\n";
        cout << "*" << a.back() << '\n';
        return;
    }

    for (int i = 0; i + 1 < a.size(); i++) {
        string sa = "";
        sa.push_back(a[i]);
        sa.push_back(a[i + 1]);
        mp[sa]++;
    }
    for (int i = 0; i + 1 < b.size(); i++) {
        string sb = "";
        sb.push_back(b[i]);
        sb.push_back(b[i + 1]);
        if (mp.count(sb)) {
            cout << "YES\n*" << sb << "*" << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}